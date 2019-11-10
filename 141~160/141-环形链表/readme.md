# 141-环形链表

```c++
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 
```

示例 1：
![img](./circularlinkedlist.png)

```c++
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool hasCycle(ListNode* head) {


		ListNode* fast1 = head;
		ListNode* fast2 = head;
		ListNode* slow = head;
		while (fast2 != nullptr && fast2->next != nullptr)
		{

			fast1 = fast2->next;
			fast2 = fast1->next;

			
			if (fast1 == slow || fast2 == slow)
				return true;

			slow = slow->next;
		}
		return false;
	}
};
```

---

使用快慢指针可以很容易的求出结果，但是有一个问题，容易跳过慢指针，导致程序运行的时间变长，可以采用三指针两步走的方法，不破坏链表原有信息实现O(n)复杂度。

**具体思路是采用逐步判断快指针的方式防止跳过慢节点造成时间消耗过长。**

超过91%（其中还包括使用改变节点信息的解）
