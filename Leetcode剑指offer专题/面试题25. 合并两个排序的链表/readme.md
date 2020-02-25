# 面试题25. 合并两个排序的链表

```c++
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000

注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

注意1点：当任意一个链表结束时，直接将当前的尾部接到还没有结束的链表头部即可。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* m = prehead;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                m->next = l1;
                l1 = l1->next;
            }
            else{
                m->next = l2;
                l2 = l2->next;
            }
            m = m->next;
        }
        m->next = l1 == NULL ? l2 : l1;
        return prehead->next;
    }
};
```

---



