# 24. 两两交换链表中的节点

```c++
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* pre = new ListNode(0);
		pre->next = head;
		ListNode* temp = pre;
		while (temp->next != nullptr && temp->next->next != nullptr) {
			ListNode* start = temp->next;
			ListNode* end = temp->next->next;
			temp->next = end;
			start->next = end->next;
			end->next = start;
			temp = start;
		}
		return pre->next;
	}
};
*/


//还有一种递归解法,在leetcode这种方法执行用时反而更短，内存消耗和第一种方法相同
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了90.33%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了72.97%的用户
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head != nullptr && head->next != nullptr ) {  //短路求值
			auto t = head->next;
			head->next = swapPairs(head->next->next);
			t->next = head;
			return t;
		}
		else {
			return head;
		}
		
	}
};


int main()
{
	Solution s = Solution();

	ListNode* input;
	input = new ListNode(1);
//	input->next = new ListNode(2);
//	input->next->next = new ListNode(3);
//	input->next->next->next = new ListNode(4);

	auto ans = s.swapPairs(input);

	while (ans != nullptr) {
		cout << ans->val <<" , " ;
		ans = ans->next;
	}
	//cout << s.threeSum(input) << endl;

	return 0;
}

```

---
