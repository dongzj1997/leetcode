# 124. 二叉树中的最大路径和

```c++
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int ans = INT_MIN;

	int maxPathSum(TreeNode* root) {
		if (root == NULL) {
			return 0;
		
		}
		helper(root);

		return ans;
	}

	int helper(TreeNode* root) {  //获得以该节点为开始的最大值
		if (root == NULL) {
			return 0;
		}
		int left = max(helper(root->left),0);   //返回左右子树的最大值
		int right = max(helper(root->right), 0); //如果为负，则为0 ，表示不包含子树
		if (root->val + left + right > ans)  //以该节点为中心的最大值
			ans = root->val + left + right;

		return max(left, right) + root->val; 
	}
};
```

---
对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:

1. 其左右子树中所构成的和路径值较大的那个加上该节点的值后向父节点回溯构成最大路径

2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径

递归的求得左右节点的最大值即可。
