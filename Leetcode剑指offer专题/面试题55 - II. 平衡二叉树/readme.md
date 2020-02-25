# 面试题55 - II. 平衡二叉树

```c++
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

 

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

 

限制：

1 <= 树的结点个数 <= 10000
注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

本质还是求高度，但返回值为是否平衡，所以可以用一个不可能出现的高度-1来表示不平衡，父节点遇到-1也直接返回-1即可，最终结果判断返回的是-1还是正常高度。 这样只需要递归一次，节省时间。



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
	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		return gitDeep(root) > 0;
	}

	int gitDeep(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int l = gitDeep(root->left);
		int r = gitDeep(root->right);

		if (l < 0 || r < 0 || l - r >= 2 || r - l >= 2) {
			return -1;
		}
		return max(l,r ) + 1;
	}
};
```

---



