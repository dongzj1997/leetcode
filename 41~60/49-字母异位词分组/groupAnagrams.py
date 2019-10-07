class Solution:
    def groupAnagrams(self, strs) :
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]
        dic = {}
        for s in strs:
            key = 1
            for c in s:
                key *= prime[ord(c) - 97]
            if key in dic:
                dic[key].append(s)
            else:
                dic[key] = [s]

        return list(dic.values())


a = Solution()
ans = a.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
