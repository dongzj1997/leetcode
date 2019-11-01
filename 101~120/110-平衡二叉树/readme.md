# 110. 平衡二叉树

```c++
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return 1;
		}
		return gitDeep(root)>0;
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

执行用时 :12 ms, 在所有 cpp 提交中击败了96.09%的用户

内存消耗 :17.2 MB, 在所有 cpp 提交中击败了63.44%的用户

---

本题的关键是求出树左右两边的高度，根节点的高度是左右两边取大值然后+1，在取最大高度时判断两边的差距是不是大于1，如果大于1，则返回-1，表示不平衡。

