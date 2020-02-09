# 500-键盘行

```c++
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        set1, set2, set3 = set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")
        ans = []
        for i in words:
            st = set(i.lower())
            if st <= set1 or st <= set2 or st <= set3:
                ans.append(i)
        return ans
```

---



