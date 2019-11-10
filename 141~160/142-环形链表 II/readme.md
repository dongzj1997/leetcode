# 142-环形链表 II

```c++
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fastPtr = head, * slowPtr = head;
		
		while (fastPtr != NULL && fastPtr->next != NULL)
		{
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
			if (fastPtr == slowPtr) //第一次相遇
			{
				// 从相遇点再走“非环部分长度”一定可以再次走到环起点
				fastPtr = head;
				while (fastPtr != slowPtr)
				{
					fastPtr = fastPtr->next;
					slowPtr = slowPtr->next;
				}
				return fastPtr;
			}
		}

		return nullptr;
	}
};

```

---

为了找到环的入口，我们分步讨论：

1. 假设链表头节点到环入口节点的距离为n，在慢节点走了n/2 时，快节点已经到了位置n

2. 当慢节点到位置 n 时，快节点已经在环内部走了 n 的长度，假设它此时到环的入口距离为 b （环的长度为 n+b）。

3. 慢节点再在环内走 b 的距离，此时快节点已经可以走 2b的距离，加上之前的，已经在环内走了 n+ 2b 的距离。

4. 此时，慢节点距离环的入口距离为 n，刚好，由于快节点已经走了一圈，第二圈时距离入口的距离也刚好为 n，说明此时他它们相遇

5. 相遇时，慢节点距离环的入口距离为 n，而n恰好为头节点到环入口处的距离，所以在头节点上新设置一个节点，让它和慢节点每次都走一步，则n步后，两者相遇，此时相遇的位置就是环入口！
