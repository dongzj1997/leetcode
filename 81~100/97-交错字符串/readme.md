最开始想直接用dfs取巧的方法得出结果，但是速度感人。
```c++
class Solution {
public:
	int len1=0, len2=0, len3=0;
	string ss1, ss2, ss3;
	bool isInterleave(string s1, string s2, string s3) {
		len1 = s1.size();
		len2 = s2.size();
		len3 = s3.size();
		ss1 = s1;
		ss2 = s2;
		ss3 = s3;
		if (len1 + len2 != len3)
			return false;

		return dfs(0, 0, 0);
	}

	bool dfs(int loc1, int loc2, int loc3) {
		if (loc3 == len3)
			return true;

		if (loc1 < len1 && loc2 < len2 && ss1[loc1] == ss3[loc3] && ss2[loc2] == ss3[loc3]) {
			return (dfs(loc1 + 1, loc2, loc3 + 1) || dfs(loc1, loc2 + 1, loc3 + 1));
		}

		if (loc1 < len1 && ss1[loc1] == ss3[loc3] ) {
			return (dfs(loc1 + 1, loc2, loc3 + 1));
		}
		if (loc2 < len2 && ss2[loc2] == ss3[loc3]) {
			return (dfs(loc1, loc2 + 1, loc3 + 1));
		}
		return false;
	}


};
```

动态规划解法：

```C++
bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = s3.size();
	if (len1 + len2 != len3)
		return false;
	vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1)); //创建动态规划数组 （大小为( len1 +1 ) *(len2 +1)）
	//dp[i][j]表示s1[0~i-1]和s2[0~j-1]能否交错组成s3[0~i+j-1]。
	dp[0][0] = true;
	for (int i = 1; i <= len1; ++i)
	{
		dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
	}
	for (int i = 1; i <= len2; ++i)
	{
		dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
	}
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j] || dp[i][j - 1] && s2[j - 1] == s3[i - 1 + j];
		}
	}
	return dp[len1][len2];
}
```