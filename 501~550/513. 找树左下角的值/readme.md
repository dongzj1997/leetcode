# 513. 找树左下角的值

```c++
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    int maxdeep = 0;
    int ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        helper(root, 1);
        return ans;
    }
    
    void helper(TreeNode* root, int deep){
        if(!root) return;
        if(deep > maxdeep){
            ans = root->val;
            maxdeep = deep;
        }
        helper(root->left, deep+1);
        helper(root->right, deep+1);
        
    }
};
```

---



