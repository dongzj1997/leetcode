# 3. 无重复字符的最长子串

```c++
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

双指针+贪心算法

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int dp[128] = {0};
        int left= 0;
        int ans = 0;
        for(int i=0;i<len;i++){
            left = max(left, dp[s[i]]);
            ans = max(ans,i-left+1);
            dp[s[i]] = i+1;
        }
        return ans;
    }
};
```

---
