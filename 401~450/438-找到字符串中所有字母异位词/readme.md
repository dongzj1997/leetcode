# 438. 找到字符串中所有字母异位词

```c++
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这种窗口固定的题应该归为简单

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        int l = 0, r = 0;
        vector<int> windows(26, 0), arm(26, 0);

        for (int i = 0; i < p.size(); i++, r++) {
            arm[p[i] - 'a']++;
            windows[s[r] - 'a']++;
        }

        if (windows == arm)
            ans.push_back(l);

        while (r < s.size()) {
            windows[s[r++] - 'a']++;
            windows[s[l++] - 'a']--;
            if (windows == arm) //其实这一步可以优化，但是时间复杂度是O（1）就算了
                ans.push_back(l);
        }
        return ans;
    }
};

```

---



