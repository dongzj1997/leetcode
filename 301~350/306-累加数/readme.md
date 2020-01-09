# 306. 累加数

```c++
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true 
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true 
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```python
class Solution:
    def isValid(num1, num2, s):
        if num1[0] == '0' and len(num1) > 1: return False
        if num2[0] == '0' and len(num2) > 1: return False
        tmp = str(int(num1)+int(num2))
        l = len(tmp)
        if s.startswith(tmp):
            num1, num2 = num2, tmp
            s = s[l:]
            if s == '': return True
            return Solution.isValid(num1, num2, s)
        return False
        
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        for i in range(1, (n + 1) //2):
            num1 = num[:i]
            for j in range(i + 1, math.floor(2/3 * n)+1):
                num2 = num[i: j]
                if Solution.isValid(num1, num2, num[j:]):
                    return True
        return False
```

---

其实只要确定了第一个数和第二个数的位置，整个的分割方式就确定了。

主要注意的是剪枝，第一个分割点不会大于整个长度的一半，第二个数的长度最大是n/3，因此j的范围最大枚举到2/3 * n

