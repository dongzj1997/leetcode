# 101. 对称二叉树

```c
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

思路其实很简单，使用递归，传进去左右两值，判断是否相等，再递归判断左值的左子树和右值的右子树，右值的左子树和左值的右子树是否相等，代码如下：

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return check(root->left,root->right);
    }
    bool check(TreeNode* node1,TreeNode* node2){
        if(node1 == NULL && node2 == NULL )
            return true;
        if(node1 != NULL && node2 != NULL && node1->val == node2->val)
            return check(node1->left,node2->right) && check(node1->right,node2->left);
        return false;
    }
};
```
