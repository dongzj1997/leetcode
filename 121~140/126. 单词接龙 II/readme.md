# 126. 单词接龙 II

```c++
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

第一次刷的时候跳过了，每日一题来填坑。

```c++
class Solution {
	void dfs(unordered_map<string,unordered_set<string> > &trace, const string &last, vector<string> path, vector<vector<string> > &vs){
		path.push_back(last);
		if(trace.count(last)==0){
			reverse(path.begin(),path.end());
			vs.push_back(path);
			return;
		}
		for(const string &word:trace[last])
			dfs(trace,word,path,vs);
	}
public:
	vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if (dict.count(end)==0) return {};
		unordered_map<string,unordered_set<string> > trace;
		unordered_set<string> q={begin}, dels;
		for(; q.size() && trace.count(end)==0; q=dels){
			for(const string &word:q)
				dict.erase(word);
			dels.clear();
			for(const string &word:q){
				for(int i=0; i<word.length(); ++i){
					string s=word;
					for(char ch='a'; ch<='z'; ++ch){
						if(word[i]==ch) continue;
						s[i] = ch;
						if(dict.find(s)==dict.end()) continue;
						trace[s].insert(word);
						dels.insert(s);
					}
				}
			}
		}
		if(trace.count(end)==0) return {};
		vector<vector<string> > result;
		dfs(trace,end,{},result);
		return result;
	}
};

```

---



