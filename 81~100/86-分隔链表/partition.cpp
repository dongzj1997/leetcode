class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* left = new ListNode(0);
		ListNode* right = new ListNode(0);
		ListNode* curleft = left, *curright = right;
		
		//ListNode* cur = new ListNode(0);
		while (head) {
			if (head->val < x) {
				curleft->next = head;
				curleft = curleft->next;
			}
			else {
				curright->next = head;
				curright = curright->next;
			}
			ListNode* t = head->next;
			head->next = NULL;
			head = t;
		}

		curleft->next = right->next;
		return left->next;
	}
};
