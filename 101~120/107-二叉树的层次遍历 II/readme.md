# 107. 二叉树的层次遍历 II

```c++
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

好像除了每次都往列表头塞或者直接逆序以后也没啥别的好的方法
（这里用的是逆序，速度不太行，往列表头好一点）

```c++
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr) {
			return vector<vector<int>>{};
		}
		vector<vector<int>> ans;
		queue<TreeNode*> S1 = {};
		queue<TreeNode*> S2 = {};
		S1.push(root);

		while (!S1.empty()) {
			vector<int> layer = {};
			while (!S1.empty()) {
				
				TreeNode* t = S1.front();
				layer.push_back(t->val);
				if (t->left != NULL)
					S2.push(t->left);
				if (t->right != NULL)
					S2.push(t->right);
				S1.pop();

			}
			queue<TreeNode*> t = S1;
			S1 = S2;
			S2 = t;
			ans.push_back(layer);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
```
