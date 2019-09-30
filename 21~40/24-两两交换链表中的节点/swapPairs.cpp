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
