# 10-正则表达式匹配

```c++
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1，递归

每解析一个字符（或者 .*）就递归一次

注意判断各个情况时的前驱条件。

多看代码

```c++
class Solution {
public:
	int s_len;
	int p_len;
	bool isMatch(string s, string p) {
		s_len = s.size();
		p_len = p.size();
		return helper(0, 0, s, p);  //  s = "mississippi"  p = "mis*is*p*."       
	}

	bool helper(int s_left, int p_left, string& s, string& p) {
		if (p_left == p_len) //p已经解析完，现在只需返回s是否也刚好解析完即可。
			return s_left == s_len;

		bool head_match = (s_left < s_len) && (s[s_left] == p[p_left] || p[p_left] == '.');

		if (p_left + 1 < p_len && p[p_left + 1] == '*') { //处理 * 的情况
			// a* 无视  ||   
			return helper(s_left, p_left + 2, s, p) || head_match && helper(s_left + 1, p_left, s, p);
		}

		//正常匹配
		return head_match && helper(s_left + 1, p_left + 1, s, p);
	}
};
```

---

## 解法2，动态规划

有几种情况，假设现在解析到了`dp[i][j]` 

1. `s[i] == p[j]` 说明该位置对上了，`dp[i][j] = dp[i-1][j-1]`

2. `p[j] == '.'` , 直接`dp[i][j] = dp[i-1][j-1]`

3. `p[j] == '*'`, 有两种情况

    1) 第一种是前一个字符对不上， `p[j-1] != s[i] && p[j-1] != '.' `，直接`dp[i][j] = dp[i][j-2]`

    2） 第二种是可以对上，又可以分为两种情况，继续重复该字符和不再重复该字符，代码为`dp[i][j] = dp[i-1][j] || dp[i][j - 2]`


如果是其他情况，`dp[i][j]` 保持false即可。

```c++
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0) {
			return s.size()==0;
		}
		vector<vector<bool> > dp( s.size() + 1, vector<bool>(p.size() + 1, 0) );
		dp[0][0] = true;//dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
		for (int i = 0; i < p.size(); i++) { // here's the p's length, not s's
			if (p[i] == '*' && dp[0][i - 1]) {
				dp[0][i + 1] = true; // here's y axis should be i+1
			}
		}
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < p.length(); j++) {
				if (p[j] == '.' || p[j] == s[i]) {//如果是任意元素 或者是对于元素匹配
					dp[i + 1][j + 1] = dp[i][j];
				}
				if (p[j] == '*') {
					if (p[j-1] != s[i] && p[j-1] != '.') {//如果前一个元素不匹配 且不为任意元素
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					}
					else {
						dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j - 1]);

					}
				}
			}
		}
		return dp[s.size()][p.size()];
	}

};

```

