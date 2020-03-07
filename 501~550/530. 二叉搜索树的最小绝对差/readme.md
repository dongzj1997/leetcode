# 530. 二叉搜索树的最小绝对差

```c++
给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

示例 :

输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---
简单

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
    TreeNode* pre = NULL;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return ans;

        getMinimumDifference(root->left);
        if(pre)
            ans = min(ans, root->val - pre->val);
        pre = root;
        getMinimumDifference(root->right);
        return ans;
    }
};
```

---



