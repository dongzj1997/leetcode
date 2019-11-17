# 234. 回文链表

```c++
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head, * fast = head, * prev = nullptr;
		while (fast) {//找到中点
			slow = slow->next;
			fast = fast->next ? fast->next->next : fast->next;
		}
		while (slow) {//翻转
			ListNode* ovn = slow->next;
			slow->next = prev;
			prev = slow;
			slow = ovn;
		}
		while (head && prev) {//检查
			if (head->val != prev->val) {
				return false;
			}
			head = head->next;
			prev = prev->next;
		}
		return true;
	}
};
```

---

和把大象装进冰箱医院，需要三步：

1. 快慢节点，找出链表的中点

2. 翻转链表的后半段

3. 逐个比较

还有一个更快的方法，懒得写了

就是在找中点的时候就把链表的前半段反转好，然后直接比较就行了。

