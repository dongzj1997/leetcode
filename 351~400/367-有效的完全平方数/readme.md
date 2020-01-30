# 367. 有效的完全平方数

```c++
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

二分查找，防止int的溢出

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = min(46340,num);
        while(l<r){
            int mid = l+(r-l)/2; // 防止溢出
            if(mid*mid<num){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return num==r*r;
    }
};
```

---

## 解法2 数学公式

等差数列 `1+3+5+7+...(2N−1)=N^2`

算法简单，但是效率感人

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0
```

## 解法3 使用牛顿迭代法求解

`x(n+1) = x(n) - f(x(n)) / f'(x(n))`

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = num
        while i * i > num:
            i = (i + num / i) // 2
        return i * i == num
```
