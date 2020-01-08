# 279. 完全平方数

```c++
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

类似背包问题，使用dp加快速度

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++) 
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};
```

---

如果使用递归也可以，但是时间大约为上述解法的十倍

```C++
class Solution {
public:
	unordered_map<int, int> dp;
	int numSquares(int n) {
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		dp[4] = 1;

		return helper(n);
		

	}

	int helper(int n) {
		if (dp.count(n) != 0) //这个值计算过
			return dp[n];
		else {
			int ans = INT_MAX;
			for (int t = 1; t * t <= n; t++) {
				int a = helper(n - t * t) + 1;
				ans = ans < a ? ans : a;
			}
			dp[n] = ans;
			return ans;
		}
	}
};
```

