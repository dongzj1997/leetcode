# 337. 打家劫舍 III

```c++
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

用两个helper函数的非主流版

注意带记忆性的递归和非记忆性的递归差别很大：

1. 原始的不带`unordered_map<TreeNode*, int> mem;`的
![1](1.bmp)

2. 带`unordered_map<TreeNode*, int> mem;`的
![2](2.bmp)


```c++
class Solution {
public:
	unordered_map<TreeNode*, int> mem;
	int rob(TreeNode* root) {

		return helper1(root);
	}
	int helper1(TreeNode* root) { //root节可以选取
		if (root == NULL) {
			return 0;
		}
		if (mem.count(root)) {
			return mem[root];
		}
		// 不选root，所以两边节点可以选
		int a = helper1(root->left) + helper1(root->right);

		//选root，两边节点不可选
		int b = root->val + helper2(root->left) + helper2(root->right);

		int ans = max(a, b);
		mem[root] = ans;
		return ans;
	}

	int helper2(TreeNode* root) { //root节点不可选取
		if (root == NULL) {
			return 0;
		}

		return helper1(root->left) + helper1(root->right);
	}
};

```

---



