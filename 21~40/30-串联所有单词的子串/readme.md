# 30-串联所有单词的子串

```c++
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

自己写了半天，逻辑勉强对的，就是代码太乱，就不贴了。

此处贴一个评论区高赞方法 [@zhangyuan](https://leetcode-cn.com/u/zhangyuan-4/)

加速点主要有两个：

1. 某个位置匹配错误时，直接将光标移到错误位置的下一个。

2. 某个位置相同word数量过多时，不断--，直到数量正常。

```c++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        unordered_map<string, int> wordmap, smap;
        for (string word : words) wordmap[word]++;
        int wordlen = words[0].size();
        int wordnum = words.size();
        vector<int> ans;
        for (int k = 0; k < wordlen; k++) {
            int i = k, j = k;
            while (i < s.size() - wordnum * wordlen + 1) {
                while (j < i + wordnum * wordlen) {
                    string temp = s.substr(j, wordlen);
                    smap[temp]++;
                    j += wordlen;
                    if (wordmap[temp] == 0) {//情况二，有words中不存在的单词
                        i = j;//对i加速
                        smap.clear();
                        break;
                    }
                    else if (smap[temp] > wordmap[temp]) {//情况三，子串中temp数量超了
                        while (smap[temp] > wordmap[temp]) {
                            smap[s.substr(i, wordlen)]--;
                            i += wordlen;//对i加速
                        }
                        break;
                    }
                }
                //正确匹配，由于情况二和三都对i加速了，不可能满足此条件
                if (j == i + wordlen * wordnum) {
                    ans.push_back(i);
                    smap[s.substr(i, wordlen)]--;
                    i += wordlen;//i正常前进
                }
            }
            smap.clear();
        }
        return ans;
    }
};
```

---



