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
        return s[pos+1-(maxlen+1)//2:pos+1+maxlen//2]  # 防止最长串为偶数，分割点在中间的情况

    def longestSeq(self, s: str, left: int, right: int) -> int:
        strlen = len(s)
        while left >= 0 and right < strlen and s[left] == s[right]:
            left -= 1
            right += 1
        return right-left-1


"""

S = Solution()
s = S.longestPalindrome("cbbabbd")
print(s)

"""

