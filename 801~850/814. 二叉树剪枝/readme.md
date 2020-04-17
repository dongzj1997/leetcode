# 814. 二叉树剪枝

```c++

```

---

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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        auto l = pruneTree(root->left);
        if(l == NULL) root->left = NULL;
        auto r = pruneTree(root->right);
        if(r == NULL) root->right = NULL;
        
        if(root->val == 0 && l == NULL && r == NULL){
            //delete root;
            root = NULL;
        }
        return root;
    }
};
```

或者直接传一个引用：

```c++
class Solution {
public:
    TreeNode* pruneTree(TreeNode* &root) {
        if(!root) return NULL;
        auto l = pruneTree(root->left);
        auto r = pruneTree(root->right);
        if(root->val == 0 && l == NULL && r == NULL){
            root = NULL;
        }
        return root;
    }
};
```

---



