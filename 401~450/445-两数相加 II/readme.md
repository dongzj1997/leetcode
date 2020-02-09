# 445-两数相加 II

```c++
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

 

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个题没创意

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        
        //根据链表构建两个栈
        stack<int> s1,s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!= NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        //根据两个栈计算数值并建表
        int carry = 0,n1 = 0,n2 = 0,sum = 0;
        ListNode* dummy = new ListNode(-1);//创建头节点
        ListNode* tmp = NULL;
        while(!s1.empty() || !s2.empty() || carry){
            
            if(s1.empty())n1 = 0;
            else {n1 = s1.top();s1.pop();}
            
            if(s2.empty())n2 = 0;
            else{n2 = s2.top();s2.pop();}
            
            sum = (n1 + n2 + carry);
            
            //头插法建表
            tmp = new ListNode(sum%10);
            tmp->next = dummy->next;
            dummy->next = tmp;
            
            //处理进位，给下一次迭代用
            carry = sum/10; 
        }
        
        return dummy->next;//注意别把头节点也一起返回了
    }
};

```

---



