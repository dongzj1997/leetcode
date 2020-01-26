# 342. 4的幂

```c++
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0 || num & (num-1)) //判断是否为2的幂
            return false;
        return num & 0x55555555;//来校验奇数位上的1
    }
};
```

---



