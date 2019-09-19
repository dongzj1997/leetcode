class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        tmp = 0

        left = 0
        d = {}

        for i in range(len(s)):
            if s[i] in d:
                left = max(d[s[i]], left)  #在上一次出现的位置和当前的左窗口之间取最大值
            ans = max(ans, i-left+1)
            d[s[i]] = i+1

        return ans