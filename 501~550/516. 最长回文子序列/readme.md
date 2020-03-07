# 516. 最长回文子序列

```c++
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

现在这种程度的dp就是小试牛刀

```c++
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int len = s.size();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; i++) {
			dp[i][i] = 1;
		}
		for (int i = 1; i < len; i++) {
			for (int j = i - 1; j >= 0; j--) {

				if (s[i] == s[j]) {
					dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + 2);
				}
				int t = max(dp[j + 1][i], dp[j][i - 1]);
				dp[j][i] = max(t, dp[j][i]);
			}
		}
		return dp[0][len - 1];

	}
};
```

---



