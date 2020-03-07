# 508. 出现次数最多的子树元素和

```c++
给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。

 

示例 1
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2
输入:

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

 

提示： 假设任意子树元素和均可以用 32 位有符号整数表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-frequent-subtree-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

不难

```c++
class Solution {
public:
	unordered_map<int, int> mp;
	int mx;
	vector<int> findFrequentTreeSum(TreeNode* root) {
		helper(root);
		vector<int> ans;
		for (auto c : mp) {
			if (c.second == mx)
				ans.push_back(c.first);
		}
		return ans;
		
	}
	int helper(TreeNode* root) {
		if (!root)
			return 0;
		int l = helper(root->left);
		int r = helper(root->right);
        int sum = l+r+root->val;
		mp[sum]++;
		mx = max(mx, mp[sum]);
        return sum;

	}
};
```

---



