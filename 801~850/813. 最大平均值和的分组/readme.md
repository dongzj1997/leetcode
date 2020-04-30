# 813. 最大平均值和的分组

```c++
我们将给定的数组 A 分成 K 个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。

注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。

示例:
输入: 
A = [9,1,2,3,9]
K = 3
输出: 20
解释: 
A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
我们也可以把 A 分成[9, 1], [2], [3, 9].
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
说明:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
答案误差在 10^-6 内被视为是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-sum-of-averages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---
`dp[i][k]`表示前i个数构成k个子数组时的最大平均值, 那么对状态转移方程为：

`dp[i][k] = Math.max(dp[i][k], dp[j][k-1] + (A[j+1] + ... + A[i+1]) / (i-j + 1))`

不断遍历，取最大就好，（时间复杂度`O(K*N^2)`）

比较基本的二维dp题

```c++
class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		int len = A.size();
		//[9], [1, 2, 3], [9]. 
		vector< vector<double>> dp(len, vector<double>(K, 0.0));
		int s = 0;
		for (int i = 0; i < len; i++) {
			s += A[i];
			dp[i][0] = (double)s / (i+1);
		}

		for (int k = 1; k < K; k++) {
			for (int i = 1; i < len; i++) {
				int sum = 0;
				double t = 0;
				for (int j = i; j >=1; j--) {
					sum += A[j];
					t = max(t, ((double)sum) / ((double)i - j + 1) + dp[j-1][k-1]);
				}
				dp[i][k] = t;
			}
			
		}
		return dp[len - 1][K-1];
	}
};
```

---



