# 404. 左叶子之和

```c++
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单那

```c++
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
    //int ans=0;
    int sumOfLeftLeaves(TreeNode* root) {

        return helper(root);
    }
    
    int helper(TreeNode* root){
        if(!root)
            return 0;
        if(root->left){
            if(root->left->left ==NULL && root->left->right == NULL)
                return root->left->val + helper(root->right);
        }
        return helper(root->left) + helper(root->right);
    }
};
```

---



