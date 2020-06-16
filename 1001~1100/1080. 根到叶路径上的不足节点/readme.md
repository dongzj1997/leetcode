# 1080. 根到叶路径上的不足节点

```c++
给定一棵二叉树的根 root，请你考虑它所有 从根到叶的路径：从根到任何叶的路径。（所谓一个叶子节点，就是一个没有子节点的节点）

假如通过节点 node 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 limit，则该节点被称之为「不足节点」，需要被删除。

请你删除所有不足节点，并返回生成的二叉树的根。

 

示例 1：


输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1

输出：[1,2,3,4,null,null,7,8,9,null,14]
示例 2：


输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22

输出：[5,4,8,11,null,17,4,7,null,null,null,5]
示例 3：


输入：root = [5,-6,-6], limit = 0
输出：[]
 

提示：

给定的树有 1 到 5000 个节点
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insufficient-nodes-in-root-to-leaf-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

如果左右儿子节点为不足节点，则当前节点也为不足节点 

叶节点的判断条件时路径和是否小于limit

后续遍历，然后判断是否将左右节点职位空。

使用一个哑节点来处理根节点要被删除的问题。

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        hp(dummy, 0 , limit);
        return dummy->left;
    }
    bool hp(TreeNode* root,int sum,int limit){
        if(!root) return false;

        sum += root->val;
        if( root->left == NULL && root->right == NULL) return sum >= limit;
        bool l = hp(root->left, sum, limit);
        bool r = hp(root->right, sum, limit);
        if(!l) root->left = NULL;
        if(!r) root->right = NULL;
        return l || r;
    }
};
```

---

