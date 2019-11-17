# 203. 移除链表元素

```c++
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

---

```c++
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* temp = dummy;
		while (temp->next) {
			ListNode* p = temp->next;
			if (p->val == val) {
				temp->next = p->next;
				continue;
			}

			temp = temp->next;

		}
		return dummy->next;

	}
};

```

---

记得删除节点的时候不能直接跳到下一个，要continue。（因为其实删除以后可以理解为已经是下一个了）

## 另一种写法：（递归）

```c++
ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}
```
