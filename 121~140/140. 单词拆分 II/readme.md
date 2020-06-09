# 140. 单词拆分 II

```c++
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

思路和1基本一致，注意有些用例复杂度较高，先用前一体单词拆分判断true和false，true的话再去找拆分。

使用unordered_set来计算结果。

![img](./1.bmp)

```c++
class Solution {
public:
	vector<string> ans;
	int maxStrLen = 0, minStrLen = INT_MAX;
	vector<string> wordBreak(string s, vector<string>& wordDict){
		
		vector<bool> dp(s.size() + 1, false);
		unordered_set<string> m(wordDict.begin(), wordDict.end());

		for (auto s : wordDict) {
			int len = s.size();
			maxStrLen = maxStrLen > len ? maxStrLen : len;
			minStrLen = minStrLen < len ? minStrLen : len;
		}
		vector<string> temp;
		if (ableBreak(s, wordDict)) {
			helper(s, m, 0, temp);
		}
		return ans;
	}
	void helper(string &s, unordered_set<string>& m, int deep, vector<string> &temp) {
		if (deep == s.size()) {
			gen_ans(temp);
			return;
		}

		for (int j = minStrLen; j <= maxStrLen && deep + j <= s.size(); j++) {  //j表示搜索的长度
			string t = s.substr(deep, j);

			if (m.count(t) != 0) {
				temp.push_back(t);
				helper(s, m, deep + j, temp);
				temp.pop_back();
			}
		}
	}

	bool ableBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;  //长度为len + 1，位置0表示开头
		unordered_set<string> m(wordDict.begin(), wordDict.end());

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

	void gen_ans(vector<string>& temp) {
		string t = temp[0];
		for (int i = 1; i < temp.size(); i++) {
			t += (" " + temp[i]);
		}
		ans.push_back(t);
		return;

	}
};
```

---

