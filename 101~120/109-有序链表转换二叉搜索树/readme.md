# 109. 有序链表转换二叉搜索树

```c++
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		ListNode* slow = head, * fast = head, * last = head;
		while (fast->next && fast->next->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (slow == fast && !slow->next) {  //此时的长度为1，
			return new TreeNode(slow->val);
		}
		if (slow == fast && slow->next) {//此时的长度为2，
			TreeNode* father = new TreeNode(slow->next->val);
			TreeNode* son = new TreeNode(slow->val);
			father->left = son;
			return father;
		}
		last->next = NULL;  //从slow处截断链表（不包括slow）
		TreeNode* root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);
		return root;
	}
};
```

---

我感觉其实最快的方法是，先把链表转换为数组，又快又好用，只是空间复杂度会大一点。但是既然是链表题，就用另一种方法吧。

此题的关键是快速找到链表的中点，可以用快慢指针的方法，慢指针一次跳一个，快指针一次跳两个，当快指针跳到结尾的时候，慢指针刚好就到了链表的中点。
