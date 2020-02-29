# 829. 连续整数求和

```c++
给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

示例 1:

输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:

输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
示例 3:

输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/consecutive-numbers-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

和leetcode专题[面试题57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)相同

具体解析可以看那一题

[传送门](..\Leetcode剑指offer专题\面试题57 - II. 和为s的连续正数序列\readme.md)

```c++
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for (int i = 1; N > 0; i++){
            res += (N % i == 0);
            N -=i;
        }
            
        return res;
    }
};
```

---



