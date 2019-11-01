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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> r;
        if (!root) return r;
        stack<TreeNode *> d1, d2;
        d1.push(root);
        TreeNode *curr = nullptr;
        vector<int> tmp;
        while (true) {
            while (!d1.empty()) {
                curr = d1.top();
                d1.pop();
                tmp.push_back(curr->val);
                if (curr->left) d2.push(curr->left);
                if (curr->right) d2.push(curr->right);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;

            while (!d2.empty()) {
                curr = d2.top();
                d2.pop();
                tmp.push_back(curr->val);
                if (curr->right) d1.push(curr->right);
                if (curr->left) d1.push(curr->left);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;
        }
        return r;
    }
};