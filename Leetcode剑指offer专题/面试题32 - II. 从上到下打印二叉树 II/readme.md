# 面试题32 - II. 从上到下打印二叉树 II

```c++
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            vector<int> t;
            for(int i=0;i<n;i++){
                auto cur = Q.front();
                t.push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                Q.pop();
            }
            ans.push_back(t);

        }
        
        return ans;
    }
};
```

---



