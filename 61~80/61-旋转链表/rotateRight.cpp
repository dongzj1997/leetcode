#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


/*
执行用时 :16 ms, 在所有 cpp 提交中击败了49.81%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了80.41%的用户
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		int len = 1;
		ListNode* p = head;

		if (head == nullptr || k==0) {
			return head;
		}

		ListNode* ans;
		while (p->next != nullptr) {
			len++;
			p = p->next;
		}
		
		if (len == 1) {
			return head;
		}
		k = k % len;
		
		ListNode* t = head;
		for (int i = 0; i < len - k -1; i++) {
			t = t->next;
		}

		p->next = head;
		p = t->next;
		t->next = nullptr;
		return p;
	}
};

int main()
{
	ListNode *a = new ListNode(1);



	Solution s = Solution();
	vector<vector<int>> input = { {1,4},{0,4} };
	auto as = s.rotateRight(a,6);

	/*for (auto line : a) {
		for (auto c : line) {
			cout << c << " , ";
		}
		cout << endl;
	}*/

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	//cout << a << endl;

	return 0;
}