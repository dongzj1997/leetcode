# 1048. 最长字符串链

```c++
给出一个单词列表，其中每个单词都由小写英文字母组成。

如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。

词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。

从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。
 

示例：

输入：["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] 仅由小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-string-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单的dp，

hashmap真香！

击败 75.12 %

```c++
class Solution {
public:
    vector<unordered_map<string, int> > vs;
    int longestStrChain(vector<string>& words) {
        vs = vector<unordered_map<string,int> >(17);
        int mxlen = 0;
        for(string& word : words){
            vs[word.size()][word] = 0;
            mxlen = max(mxlen, (int)word.size());
        }
        int ans = 0;
        auto & mp = vs[mxlen];
        for(auto &s : words){
            if( ans < s.size())
                ans = max(ans, hp(s));
        }
        return ans;

    }
    int hp(const string &s){
        int len = s.size();
        if(len == 1) return 1;
        if(vs[len][s] != 0) return vs[len][s];
        int ans = 1;
        for(int i=0;i<len;i++){
            string ns  = s;
            ns.erase(ns.begin()+i);
            if(vs[len-1].count(ns) != 0 ){
                ans = max(ans, hp(ns) + 1);
            }
        }
        vs[len][s] = ans;
        return ans;
    }

};
```

---

