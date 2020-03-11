# 1071. 字符串的最大公因子

```c++
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1，暴力法

不断切分str2，判断是否可以整除和是否为重复串

```python
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        l1 = len(str1)
        l2 = len(str2)
        for i in range(1, l2+1):
            if(l2 % i == 0 and l1 %(l2//i) == 0):
                t = str2[:l2//i]
                if(t * i == str2 and t * (l1 //(l2//i)) == str1 ):
                    return t
        return ""
```

---

## 方法2，欧几里得算法

所以如果 `str1 + str2 == str2 + str1` 就意味着有解。

然后将str1，str2 两个长度作为欧几里得算法的参数，求这个的最公约束，就是最终的解

0ms， 还是强

```c++
class Solution {
public:
    int gcd(int a, int b) {return b == 0? a : gcd(b , a % b);}
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
```
