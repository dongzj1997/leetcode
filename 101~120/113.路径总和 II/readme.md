# 

```c++
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> curr;   // 当前路径
        helper(root, sum, curr, ans);
        return ans;
    }

    void helper(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        sum -= root->val;
        curr.push_back(root->val);
        if(sum == 0 && !root->left && !root->right) {
            ans.push_back(curr);   //是一个解
            return ;
        }
        if(root->left){
            helper(root->left, sum,curr,ans);
            curr.pop_back();        // 回溯
        }
        if(root->right){
            helper(root->right,sum,curr,ans);
            curr.pop_back();        // 回溯
        }
    }
};
```

---

执行用时 :8 ms, 在所有 cpp 提交中击败了99.84%的用户
内存消耗 :19.6 MB, 在所有 cpp 提交中击败了92.41%的用户

---

使用递归可以很快的求得解，大致思路和前一道题相同。注意如果一条路走不通，则使用curr.pop_back();  将该节点踢出解路径。
