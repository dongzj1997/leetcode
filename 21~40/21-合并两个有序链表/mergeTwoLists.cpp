#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//方法1  递归
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;
		else if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};


//方法2  迭代
// 对每一个 new 建立起来的对象 要记得释放，，或者不使用new 直接创建栈空间对象
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//ListNode* prehead = new ListNode(-1);
		//ListNode* prev = prehead;
		ListNode dummy = ListNode(-1);  //  ！！！  创建栈空间对象即可。
		ListNode* prev = &dummy;   // 注意这里需要取地址&
		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				prev->next = l1;
				l1 = l1->next;
			}
			else {
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}
		prev->next = l1 != NULL ? l1 : l2;

		return prev->next;
	}
};