# 148. 排序链表

```c++
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		auto dummy = new ListNode (0);
		dummy->next = head;
		auto p = head;

		int length = 0;
		while (p) {
			length++;
			p = p->next;
		}

		for (int size = 1; size < length; size *=2) {
			auto cur = dummy->next;
			auto tail = dummy;

			while (cur) {
				auto left = cur;
				auto right = cut(left, size); // 从left开始 切下size个节点，返回第二段的头
				cur = cut(right, size); // left->@->@ right->@->@  cur->@->...

				tail->next = merge(left, right);  //tail是上一次合并以后有序链表的尾部 将尾部的next指向合并之后的头部，将链表再次连接起来
				while (tail->next) {
					tail = tail->next;
				}
			}
		}
		return dummy->next;
	}

	ListNode* cut(ListNode* head, int n) {
		auto p = head;
		while (--n && p) {
			p = p->next;
		}

		if (!p) return nullptr;

		auto next = p->next;
		p->next = nullptr;//断开
		return next; //返回下一段的头节点
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode * dummy = new ListNode(0);
		auto p = dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
		}
		p->next = l1 ? l1 : l2;
		return dummy->next;
	}
};
```

---

主题算法是使用归并排序，但是由于题目要求空间复杂度是 O(1)，所以不能使用递归。因此这里使用 自底向上的 归并来解决。

从size = 1 开始，先完成相邻的两个size的merge，直到遍历一次链表，然后让size *=2，知道最后的size = 原始链表的长度。一个例子如下，对于`[4,3,1,7,8,9,2,11,5,6]`：

```C++
step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)  
step=2: (1->3->4->7)->(2->8->9->11)->(5->6)  
step=4: (1->2->3->4->7->8->9->11)->5->6  
step=8: (1->2->3->4->5->6->7->8->9->11)  
```
 
具体细节已经在代码中，已经注释的很详细了，需要注意的一点是，使用cut函数两次后，使用tail->next将排好序的链表链接到已经排好序的链表上，然后将tail移动到新链表的尾部。



