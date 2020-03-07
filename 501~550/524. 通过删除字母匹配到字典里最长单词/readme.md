# 524. 通过删除字母匹配到字典里最长单词

```c++
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出: 
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

刚好我之前写过一篇解题，就是处理这种多次调用判断是否为子序列的问题，链接如下：

[对后续挑战的一些思考--如何快速判断大量字符串](https://leetcode-cn.com/problems/is-subsequence/solution/dui-hou-xu-tiao-zhan-de-yi-xie-si-kao-ru-he-kuai-s/)

用那个思路很快就做出来了，并且效果还不错

执行用时 :60 ms, 在所有 C++ 提交中击败了96.60%的用户

```c++
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		s.insert(s.begin(), ' ');
		int len2 = s.size();
		vector<vector<int> > dp(len2, vector<int>(26, 0));
		for (char c = 'a'; c <= 'z'; c++) {
			int nextPos = -1; //表示接下来再不会出现该字符

			for (int i = len2 - 1; i >= 0; i--) {  //为了获得下一个字符的位置，要从后往前
				dp[i][c - 'a'] = nextPos;
				if (s[i] == c)
					nextPos = i;
			}
		}

		string ans = "";
		for (string& t : d) {
			int len1 = t.size();
			if (len1 < ans.size())
				continue;
			int index = 0;
			for (char c : t) {
				index = dp[index][c - 'a'];
				if (index == -1)
					break ;
			}
			if (index != -1) {
				if (t.size() == ans.size())
					ans = min(ans, t);
				else
					ans = t;

			}
				
		
		}

		return ans;
	}

};

```

---



