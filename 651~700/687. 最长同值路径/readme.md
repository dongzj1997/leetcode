# 687. 最长同值路径

```c++
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-univalue-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

和124题差不多，递归求左右子树，返回的是左右字数的值，然后根据返回值尝试更新最终结果。

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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        helper(root, root->val);
        return ans;
    }
    int helper(TreeNode* root, int v){
        if(!root) return 0;
        int l = helper(root->left, root->val);
        int r = helper(root->right, root->val);
        ans = max(ans, l+r);
        if(root->val == v)
            return (max(l, r) + 1);
        return 0;
    }
    
};
```

---



