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
	void recoverTree(TreeNode* root) {
		int count = 0;
		stack<TreeNode*> S;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		TreeNode* switch1, * switch2;
		while (!S.empty() || cur != nullptr) {
			if (cur != nullptr) {
				S.push(cur);
				cur = cur->left;
			}
			else {
				cur = S.top();
				S.pop();
				
				if (pre && pre->val > cur->val) {  //出现逆序对
					count++;
					if (count == 1) {
						switch1 = pre;
						switch2 = cur;
					}
					else {
						switch2 = cur;
					}
				}
				pre = cur;
				cur = cur->right;

			}
		}
		int t = switch1->val;
		switch1->val = switch2->val;
		switch2->val = t;
	}
};