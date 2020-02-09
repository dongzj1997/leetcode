# 430-扁平化多级双向链表

```c++
您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

 

示例:

输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
 

以上示例的说明:

给出以下多级双向链表:


 

我们应该返回如下所示的扁平双向链表:


在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

也可以用二叉树先序遍历那种做法

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while(cur){
            if(cur->child){ //先处理子链
                Node* next = cur->next;
                Node* last = cur->child;
                while(last->next) last = last->next; //last 拉到最末
                
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
                
                if(next){ //cur本来的next
                    last->next = next;
                    next->prev = last;
                }
            }
            cur = cur->next; //此处的next是经过子链处理以后的next
        }
        return head;
    }
};
```

---



