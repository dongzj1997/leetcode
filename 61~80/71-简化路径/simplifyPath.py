class Solution:
    def simplifyPath(self, path: str) -> str:
        res = ''
        ans = []
        raw = path.split('/')
        for words in raw:
            if words == '..':
                if len(ans)>0:
                    ans.pop()
                continue
            if words == '.' or words == '':
                continue
            ans.append(words)

        if len(ans) == 0:
            return '/'
        for ss in ans:
            res += '/'+ss
        return res


S = Solution()
s = S.simplifyPath("/home/")
print(s)



