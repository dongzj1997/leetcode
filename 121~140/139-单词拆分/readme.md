# 139. 单词拆分

```c++
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int maxStrLen = 0,minStrLen = INT_MAX;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;  //长度为len + 1，位置0表示开头
		unordered_set<string> m(wordDict.begin(), wordDict.end());

		for (auto s : wordDict) {
			int len = s.size();
			maxStrLen = maxStrLen > len ? maxStrLen : len;
			minStrLen = minStrLen < len ? minStrLen : len;
		}

		for (int i = 0; i < s.size(); i++) { //i 表示字符的起始位置
			if (!dp[i])
				continue;
			for (int j = minStrLen; j <= maxStrLen && i + j <= s.size(); j++) {  //j表示搜索的长度
				string t = s.substr(i, j);
				if (m.count(t) != 0) {
					dp[i + j] = true;
				}
			}
		}
		return dp[s.size()];
	}
};
```

---

先找出备选字符库中的最长字符和最短字符，maxStrLen，minStrLen，使用矩阵`vector<bool> dp(s.size() + 1, false);`存储前i个字符dp[i] 能不能表示。

从i=0 位置开始搜索，先判断dp[i]是否可以表示，如果不能直接i++,搜索s.substr(i, j);的子字符串，如果该字符串在库中，则dp[i + j] = true;

最后返回dp[s.size()];

---
执行用时 :4 ms, 在所有 cpp 提交中击败了97.73%的用户

内存消耗 :8.9 MB, 在所有 cpp 提交中击败了92.35%的用户
