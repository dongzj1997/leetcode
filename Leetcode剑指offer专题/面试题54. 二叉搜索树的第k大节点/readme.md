# 面试题54. 二叉搜索树的第k大节点

```c++
给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
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
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> S;
        TreeNode* cur = root;
        while(cur!=NULL){
            S.push(cur);
            cur = cur->right;
        }
        
        while(!S.empty()){
            auto t = S.top();
            S.pop();
            k--;
            if(k == 0)
                return t->val;
            if(t->left){
                cur = t->left;
                while(cur){
                    S.push(cur);
                    cur = cur->right;
                }
            }
        }
        
        return -1;
    }
};
```

---



