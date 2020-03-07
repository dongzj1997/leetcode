# 563. 二叉树的坡度

```c++
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

示例:

输入: 
         1
       /   \
      2     3
输出: 1
解释: 
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

一个函数需要返回两个参数，一个和，一个坡度，怎么办

引用就完事了

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
    int findTilt(TreeNode* root) {
        int sum = 0;
        return helper(root,sum);
    }
    int helper(TreeNode* root, int &sum){
        if(!root){
            sum = 0;
            return 0;
        }
        int sum_l =0,sum_r = 0;
        int a = helper(root->left,sum_l);
        int b = helper(root->right,sum_r);
        sum = sum_l+sum_r + root->val;
        return a + b + abs(sum_r- sum_l);
        
    }
};
```

---



