# 637. 二叉树的层平均值

```c++
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

没有难度

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
    unordered_map<int,double> sum;
    unordered_map<int,int> cnt;
    vector<double> averageOfLevels(TreeNode* root) {
        helper(root, 0);
        vector<double> ans;
        for(int i=0;i<sum.size();i++){
            ans.push_back(sum[i]/cnt[i]);
        }
        return ans;
    
    }
    void helper(TreeNode* root, int depth){
        if(!root) return ;
        sum[depth] += root->val;
        cnt[depth] ++;
        helper(root->left, depth+1);
        helper(root->right, depth+1);
        
    }
};
```

---



