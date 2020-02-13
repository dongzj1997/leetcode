# 44. 通配符匹配

```c++
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输入: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1，带备忘录的递归写法

48 ms, 在所有 C++ 提交中击败了63.52%的用户

磕磕绊绊，找一个bug用的时间有点长。

```c++
class Solution {
public:
	int s_len = 0;
	int p_len = 0;
	vector< vector<int>> dp;
	bool isMatch(string s, string p) {
		s_len = s.size();
		p_len = p.size();
		dp = vector< vector<int>>(s_len+1, vector<int>(p_len+1, 0));
		return helper(0, 0, s, p);
	}

	bool helper(int s_left, int p_left, string& s, string& p) {
		if (dp[s_left][p_left] != 0)
			return dp[s_left][p_left] == 1;
		bool ans = false;
		if (p_left == p_len)
			ans = s_left == s_len;
		else if (s_left == s_len) {
			if (p[p_left] == '*')
				ans = helper(s_left, p_left + 1, s, p);
			else
				ans = false;
		}
		else if (p[p_left] == '?' || s_left< s_len && p[p_left] == s[s_left])
			ans = helper(s_left + 1, p_left + 1, s, p);
		else if (p[p_left] == '*')
			ans = helper(s_left, p_left + 1, s, p) || helper(s_left + 1, p_left, s, p);

		dp[s_left][p_left] = ans ? 1 : -1;

		return ans;
	}
};
```

---

## 解法2，动态规划

注意对第一行的初始化，为了应对`p`开头就是`*`的情况

class Solution {
public:
	bool isMatch(string s, string p) {
		int s_len = s.size();
		int p_len = p.size();
		vector<vector<bool> >dp(s_len+1, vector<bool>(p_len+1, false));
		dp[0][0] = true;

		for (int j = 1; j <= p_len; j++) {
			if (p[j - 1] == '*') dp[0][j] = true;
			else break;
		}//处理p前缀是多个****的情况

		for (int i = 0; i < s_len; i++) {
			for (int j = 0; j < p_len; j++) {
				if (s[i] == p[j] || p[j] == '?') {
					dp[i + 1][j + 1] = dp[i][j];
				}
				else if(p[j] == '*'){
					dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
				}

			}
		}
		return dp[s_len][p_len];
	}
};
