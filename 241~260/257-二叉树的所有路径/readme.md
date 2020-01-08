# 257-二叉树的所有路径

```c++
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == nullptr) return res;

		helper(root, res, "");
		return res;
	}

	void helper(TreeNode * root, vector<string> & res, string path) {
		path += to_string(root->val);

		if (root->left == nullptr && root->right == nullptr) {
			res.push_back(path);
			return;
		}

		if (root->left) helper(root->left, res, path + "->");
		if (root->right) helper(root->right, res, path + "->");
	}
};
```

---

难度easy的意思就是easy

