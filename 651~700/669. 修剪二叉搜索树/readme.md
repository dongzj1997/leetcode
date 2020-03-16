# 669. 修剪二叉搜索树

```c++
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入: 
    1
   / \
  0   2

  L = 1
  R = 2

输出: 
    1
      \
       2
示例 2:

输入: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出: 
      3
     / 
   2   
  /
 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

顺着思路递归的解决。

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val < L)
            return trimBST(root->right,L,R);
        if(root->val >R)
            return trimBST(root->left,L,R);
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;

    }
};
```

---



