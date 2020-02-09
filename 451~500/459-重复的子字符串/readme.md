# 459-重复的子字符串

```c++
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc"

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-substring-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

假设原字符串为`s`，它由`n`个重复字串`x`构成（`s = nx`，如果不是重复子串，则`n = 1`）.

现构造新字符串`t=2s`，即两个`s`相加，由于`s=nx`，则`t=2nx`。

去掉`t`的开头与结尾两位，则这两处的子串被破坏掉，此时`t`中包含`2n-2`个子串。 若此时`t`中还包含`s`，则有`2n-2>=n`，可得`n>=2`，说明`s`至少由2个重复的子串`x`构成。

如果此时`t`中不含`s`，则只有一种可能，`n =1`，不符合条件。

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s+s)[1:-1]
```

---



