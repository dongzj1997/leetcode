# 318. 最大单词长度乘积

```c++
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

使用位运算可以又快又好地解题

注意位运算的优先级较低，记得加括号（尤其是后面接有赋值语句的时候）

```c++
class Solution {
public:
	int maxProduct(vector<string>& words) {
		int len = words.size();
		vector<int> bit(len, 0);
		vector<int> wordLen(len, 0);
		for (int i = 0; i < len;i++) {
			wordLen[i] = words[i].size();
			for (char c : words[i]) {
				int offset = c - 'a';
				int t = 1;
				t <<= offset;
				bit[i] |= t;
			}
		}

		int ans = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if( (bit[i] & bit[j]) == 0){  //位运算的优先级较低，记得加括号
					ans = max(ans, wordLen[i] * wordLen[j]);
				}
			}
		}
		return ans;

	}
};
```

---



