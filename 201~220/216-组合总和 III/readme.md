# 216-组合总和 III

```c++
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用回溯法，定义一个helper函数来解题

此题的关键是如何剪枝，我们使用的策略如下：

因为是取组合数，所以最大的问题是去重，这里去重的策略是从小到大取数，记录上层的取数值，以后只能取比这个数大的数。

当只剩一个取数名额时，可以结束递归，判断是否为有效值。

```c++
class Solution {
public:

	vector<vector<int>> ans;
	vector<int> temp;
	vector<vector<int>> combinationSum3(int k, int n) {
		helper(k, n,0);
		return ans;
	}

	void helper(int k, int n,int m) {  //pick的数一定要大于m （k为还可以取几个数，n为目标数）
		if (n <= m || m >=9)
			return;
		if (k == 1) {
			if (n > 9)
				return;
			temp.push_back(n);
			ans.push_back(temp);
			temp.pop_back();
			return;
		}
		else {
			for (int i = m + 1; i <= 9; i++) {
				temp.push_back(i);
				helper(k - 1, n - i, i);
				temp.pop_back();
			}
		}
	}
};
```
---



