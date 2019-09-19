/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* L = new ListNode(0);
		ListNode* head = L;
		int carry = 0;

		while (l1 || l2) {
			int num1 = 0, num2 = 0;  //不能写为int num1, num2 = 0; 否则num1 不会正确初始化
			if (l1) {
				num1 = l1->val;
				l1 = l1->next;
			}
			if (l2) {
				num2 = l2->val;
				l2 = l2->next;
			}
			int sum = num1 + num2 + carry;
			carry = sum / 10;
			L->next = new ListNode(sum % 10);
			L = L->next;

		}
		if (carry) {
			L->next = new ListNode(1);
		}
		L = head;
		head = head->next;
		delete L;
		return head; //防止内存泄漏
	}
};