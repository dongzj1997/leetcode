# 712. 两个字符串的最小ASCII删除和

```c++
给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。

示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
注意:

0 < s1.length, s2.length <= 1000。
所有字符串中的字符ASCII值在[97, 122]之间。
```

---

虽然做过“编辑距离”那道题以后这道题就是easy难度。

但是一遍过没bug还是很开心。

```c++
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int len1 = s1.size(), len2 = s2.size();
		vector <vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
		int t = 0;
		for (int i = 1; i <= len1; i++) {
			t += s1[i - 1];
			dp[i][0] = t;
		}
		t = 0;
		for (int i = 1; i <= len2; i++) {
			t += s2[i - 1];
			dp[0][i] = t;
		}
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j];
				else {
					dp[i + 1][j + 1] = min(dp[i + 1][j] + s2[j], dp[i][j + 1] + s1[i]);
				}
			}
		}
		return dp[len1][len2];
	}
};
```

---



