# 691. 贴纸拼词

```c++
我们给出了 N 种不同类型的贴纸。每个贴纸上都有一个小写的英文单词。

你希望从自己的贴纸集合中裁剪单个字母并重新排列它们，从而拼写出给定的目标字符串 target。

如果你愿意的话，你可以不止一次地使用每一张贴纸，而且每一张贴纸的数量都是无限的。

拼出目标 target 所需的最小贴纸数量是多少？如果任务不可能，则返回 -1。

 

示例 1：

输入：

["with", "example", "science"], "thehat"
输出：

3
解释：

我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
此外，这是形成目标字符串所需的最小贴纸数量。
示例 2：

输入：

["notice", "possible"], "basicbasic"
输出：

-1
解释：

我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
 

提示：

stickers 长度范围是 [1, 50]。
stickers 由小写英文单词组成（不带撇号）。
target 的长度在 [1, 15] 范围内，由小写字母组成。
在所有的测试案例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选取的，目标是两个随机单词的串联。
时间限制可能比平时更具挑战性。预计 50 个贴纸的测试案例平均可在35ms内解决。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stickers-to-spell-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

hard问题在网页端写的代码，没出啥问题。  感觉我越来越强了

```c++
class Solution {
public:
    unordered_map<string, int> mp;
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int> > dic(stickers.size(), vector<int>(26, 0));
        for (int i = 0; i < stickers.size(); i++) {
            string& s = stickers[i];
            for (char c : s) {
                dic[i][c - 'a'] ++;
            }
        }
        vector<int> tg(26, 0);
        for (char c : target) {
            tg[c - 'a']++;
        }

        int ans = helper(dic, tg);
        return ans >= 1e9 ? -1 : ans;
    }

    int helper(vector<vector<int> >& dic, vector<int>& tg) {
        string s_tg = vec_to_str(tg);
        if (mp.count(s_tg) != 0) return mp[s_tg];
        if (s_tg == "") return 0;
        int len = dic.size();
        int ans = 1e9;
        for (int i = 0; i < dic.size(); i++) {
            bool flag = false;
            vector<int> ntg(tg);
            for (int j = 0; j < 26; j++) {
                if (dic[i][j] > 0 && ntg[j] > 0) {
                    flag = 1;
                    ntg[j] -= dic[i][j];
                    ntg[j] = max(0, ntg[j]);
                }
            }
            if (flag) {
                ans = min(ans, helper(dic, ntg) + 1);
            }
        }

        mp[s_tg] = ans;
        return ans;
    }




    string vec_to_str(vector<int>& t) {
        string s = "";
        for (int i = 0; i < 26; i++) {
            if (t[i] != 0) {
                s += string(t[i], ('a' + i));
            }
        }
        return s;
    }
};
```

---



