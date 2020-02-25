# 面试题32 - III. 从上到下打印二叉树 III

```c++

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        bool flag = true;
        while(!Q.empty()){
            int n = Q.size();
            vector<int> t;
            for(int i=0;i<n;i++){
                auto cur = Q.front();
                if(flag)
                    t.push_back(cur->val);
                else
                    t.insert(t.begin(),cur->val );
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                Q.pop();
            }
            ans.push_back(t);
            flag = !flag;

        }
        
        return ans;
    }
};
```

---



