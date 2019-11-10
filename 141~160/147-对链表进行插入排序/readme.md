# 147-对链表进行插入排序

```c++
插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		ListNode* temp,* temp2;
		ListNode* temp3;

		while (head) {
			temp = head->next;
			
			temp2 = dummy;
			
			while (temp2->next != nullptr && temp2->next->val < head->val) {
				temp2 = temp2->next;
			}

			temp3 = temp2->next;
			temp2->next = head;
			head->next = temp3;

			head = temp;
		}

		return dummy->next;
	}
};
```

---

小试牛刀
