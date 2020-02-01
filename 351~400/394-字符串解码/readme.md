# 394. 字符串解码

```c++
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题思路--递归下降

类似于编译原理递归下降的那种方法

配合状态机（由于规模小，用if代替，不作跳转表了）根据状态的不同执行不同的操作

当读取`[]`的时候，定义一个遍历，遇到`[`就+1，遇到`]`就-1，当变量为0时，就是一个合法的字串，使用递归返回字串结果

```python
class Solution:
    def decodeString(self, s: str) -> str:
        ans = ""
        i = 0
        status = 0  # 默认状态
        num = 0
        while(True):
            if i >= len(s):
                return ans
            if status == 1: #连续读取数字状态
                if(str.isdigit(s[i]) ):
                    num *=10
                    num += int(s[i])
                    i+=1
                    continue
                elif s[i] == '[':
                   status = 2 #读取【】模式
                   continue
                else:
                   print("error!")
               
            if status == 2: #读取【】模式
                drgee = 1
                i+=1
                left = i
                while drgee != 0:
                    if s[i] == '[':
                        drgee +=1
                    elif s[i] == ']':
                        drgee -=1
                    i+=1
                ans += (num * self.decodeString(s[left:i-1]))
                status = 0
                continue
            
            if str.isdigit(s[i]):
                status = 1
                num = int(s[i])
                i+=1
                continue
            if(str.isalpha(s[i])):
                ans+=s[i]
                i+=1

s = Solution()
print(s.decodeString("2[abc]3[cd]ef"))
```

---

## 其他解法：

来自[@jyd](https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/)

栈:

```python
class Solution:
    def decodeString(self, s: str) -> str:
        stack, res, multi = [], "", 0
        for c in s:
            if c == '[':
                stack.append([multi, res])
                res, multi = "", 0
            elif c == ']':
                cur_multi, last_res = stack.pop()
                res = last_res + cur_multi * res
            elif '0' <= c <= '9':
                multi = multi * 10 + int(c)            
            else:
                res += c
        return res
```

---

递归

```python
class Solution:
    def decodeString(self, s: str) -> str:
        def dfs(s, i):
            res, multi = "", 0
            while i < len(s):
                if '0' <= s[i] <= '9':
                    multi = multi * 10 + int(s[i])
                elif s[i] == '[':
                    i, tmp = dfs(s, i + 1)
                    res += multi * tmp
                    multi = 0
                elif s[i] == ']':
                    return i, res
                else:
                    res += s[i]
                i += 1
            return res
        return dfs(s,0)

```