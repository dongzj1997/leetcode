# 108. 将有序数组转换为二叉搜索树

```c++
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<int> nums;
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		this->nums = nums;
		return helper(0, nums.size() - 1);
	}
	TreeNode* helper(int left, int right) {
		if (left > right) {
			return nullptr;
		}
		if (left == right) {
			return new TreeNode(nums[left]);
		}
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(left, mid - 1);
		root->right = helper(mid + 1, right);
		return root;
	}
};
```

---

每次取数组最中间的节点为根节点，记录左右边界，不断递归即可。

这种左右边界的题如果取左闭右闭区间来说更加方便。
