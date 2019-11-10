# 143-重排链表

```c++
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	void reorderList(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return;

		//使用快慢指将原链表中间隔断
		ListNode* slow = head, * fast = head;
		while (fast->next && fast->next->next) {

			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* head2 = slow->next;
		slow->next = NULL;

		//后段反转
		head2 = reverse(head2);

		//交替插入前端
		ListNode* cur = head;
		ListNode* cur2 = head2;

		while (cur && cur2) {
			ListNode* curSecond = cur2;
			cur2 = cur2->next;
			ListNode* nextCur = cur->next;
			curSecond->next = cur->next;
			cur->next = curSecond;

			cur = nextCur;
		}

	}

	ListNode* reverse(ListNode* head) { //反转链表
		ListNode* newHead = NULL;
		ListNode* temp = head;

		while (head) {
			temp = head->next;
			head->next = newHead;
			newHead = head;
			head = temp;
		}

		return newHead;
	}
};
```

---

把大象装进冰箱需要几步？ 答案是三步

同理，重排链表也需要三步：

1. 使用快慢指针找到链表的中点，割断，市值分为两个子链表

2. 将第二个子链表翻转

3. 将翻转后的子链表交替插入到第一个子链表中，即可完成。

