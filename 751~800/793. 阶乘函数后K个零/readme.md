# 793. 阶乘函数后K个零

```c++
 f(x) 是 x! 末尾是0的数量。（回想一下 x! = 1 * 2 * 3 * ... * x，且0! = 1）

例如， f(3) = 0 ，因为3! = 6的末尾没有0；而 f(11) = 2 ，因为11!= 39916800末端有2个0。给定 K，找出多少个非负整数x ，有 f(x) = K 的性质。

示例 1:
输入:K = 0
输出:5
解释: 0!, 1!, 2!, 3!, and 4! 均符合 K = 0 的条件。

示例 2:
输入:K = 5
输出:0
解释:没有匹配到这样的 x!，符合K = 5 的条件。
注意：

K是范围在 [0, 10^9] 的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

可以使用二分来快速查找

评论区看到的另一种方法：（100%）
[@timepp](https://leetcode-cn.com/u/timepp/)的解法

先给一推测值, 然后求K'. 根据差异修正推测值. K'会迅速收敛到K, 如果不收敛, 就返回0, 否则返回5.

```c++
class Solution {
public:
    int preimageSizeFZF(int K) {
        long long a = K * 5LL;
        int kk = getK(a);
        for (int i = 0; i < 100; i++) {
            if (kk == K) return 5;
            a -= (kk - K) * 5;
            kk = getK(a);
        }
        return 0;
    }
    int getK(long long n) {
        long long x = 5;
        int sum = 0;
        while (x <= n) {
            sum += n / x;
            x *= 5;
        }
        return sum;
    }
    
    
};
```

---



