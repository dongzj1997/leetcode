# 792. 匹配子序列的单词数

```c++
给定字符串 S 和单词字典 words, 求 words[i] 中是 S 的子序列的单词个数。

示例:
输入: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
输出: 3
解释: 有三个是 S 的子序列的单词: "a", "acd", "ace"。
注意:

所有在words和 S 里的单词都只由小写字母组成。
S 的长度在 [1, 50000]。
words 的长度在 [1, 5000]。
words[i]的长度在[1, 50]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-matching-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

之前做工并且写过解析的题

```c++
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        S.insert(S.begin(), ' ');
        
        int len2 = S.size();
        vector<vector<int> > dp(len2 , vector<int>(26, 0));
        
		for (char c = 'a'; c <= 'z'; c++) {
			int nextPos = -1; //表示接下来再不会出现该字符

			for (int i = len2 - 1; i>= 0; i--) {  //为了获得下一个字符的位置，要从后往前
				dp[i][c - 'a'] = nextPos;
				if (S[i] == c)
					nextPos = i;
			}
		}
        
        int ans = 0;
        for(string s:words){
            int len1 = s.size();
            int index = 0;
            for (char c : s) {
                index = dp[index][c - 'a'];
                if (index == -1){
                    goto L;
                }
            }
            ans++;
L:          int aaa;
        }
        return ans;
    }
};



```

---



