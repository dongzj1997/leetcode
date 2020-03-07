# 515. 在每个树行中找最大值

```c++
您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单题

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
    vector<int> res;
    vector<int> largestValues(TreeNode* root) {
        helper(root,0);
        return res;
    }
    
    void helper(TreeNode* root,int depth)
    {
        if(!root)
            return;
        if(depth>=res.size())
            res.push_back(INT_MIN);
        res[depth]=max(res[depth],root->val);
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
};
```

---



