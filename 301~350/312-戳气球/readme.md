# 312. 戳气球

```c++
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析：

`dp[i][j]`表示第i至第j个元素这个区间能获得的最大硬币数，`k`表示在`i`,`j`这个区间内最后戳破的气球，状态转移方程
`dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])`

(表示先吧k左边的气球戳爆，然后把k右边的气球戳爆，最后戳爆k)

使用自底向上的动态规划，不断扩大区间长度，求解。

```c++
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		for (int len = 1; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) { //i 为起始位置
				int j = i + len - 1; //j为终止位置
				for (int k = i; k <= j; k++) {
					dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
				}
			}
		}
		return dp[1][n];

	}
};
```

---



