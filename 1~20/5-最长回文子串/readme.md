# 5. 最长回文子串

```c++
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

中心扩散

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        pos=0
        maxlen=0
        strlen = len(s)
        for i in range(strlen):
            l1 = self.longestSeq(s, i, i)
            l2 = self.longestSeq(s, i, i+1)
            if l2 > maxlen:
                pos, maxlen = i, l2
            if l1 > maxlen:
                pos, maxlen = i, l1
        return s[pos+1-(maxlen+1)//2:pos+1+maxlen//2]

    def longestSeq(self, s: str, left: int, right: int) -> int:
        strlen = len(s)
        while left >= 0 and right < strlen and s[left] == s[right]:
            left -= 1
            right += 1
        return right-left-1
```

---
