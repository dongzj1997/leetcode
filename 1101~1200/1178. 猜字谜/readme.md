# 1178. 猜字谜

```c++
外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。

 

示例：

输入：
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
输出：[1,1,3,2,4,0]
解释：
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa" 
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
 

提示：

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] 都是小写英文字母。
每个 puzzles[i] 所包含的字符都不重复。
通过次数1,330提交次数4,736

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---



```c++

//超时版（个人认为时间复杂度还行）
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<vector<int> > vc(26, vector<int>());
        for(auto& s:words){
            int t = 0;
            for(auto c:s){
                t |= (1 << (c-'a') );
            }
            for(int i=0;i<26;i++){
                if( t & (1 << i) ){
                    vc[i].push_back(t);
                }
            }
        }


        vector<int> ans;
        for(auto &s :puzzles){
            auto & vvc = vc[s[0] - 'a'];
            int t = 0;
            for(auto c:s){
                t |= (1 << (c-'a') );
            }
            int cnt = 0;
            for(int tp: vvc){
                if( (tp | t) == t)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

```c++

//AC版,生成我们需要的组合数（一个字符串最多可生成 2^7个）
//看清题设条件，此题puzzles[i].length == 7，所以使用生成的方法更加方便。

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size();
        vector<int>res(n,0);
        unordered_map<int,int>mp;
        for(string word : words){
            int m=0;
            for(char w : word){
                m|=1<<(w-'a');
            }
            mp[m]++;
        }
        for(int i=0;i<n;i++){
            vector<int>vec;
            dfs(puzzles[i],vec,0,0);
            for(int v : vec){
                res[i]+=mp[v];
            }
        }
        return res;
    }
    void dfs(string s,vector<int>& vec,int v,int index){
        if(index==s.size()){
            vec.push_back(v);
            return;
        }
        if(index!=0) dfs(s,vec,v,index+1);
        dfs(s,vec,v|(1<<s[index]-'a'),index+1);
    }
};
```
---

