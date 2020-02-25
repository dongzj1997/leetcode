# 面试题14- II. 剪绳子 II

```c++
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个题取余之后max函数失效，需要使用别的方法。

有一种基于数学推导的贪心算法，尽可能的分为多个3，如果刚好剩下1，则和最后一个3合并为4。

具体证明过程在[这里](https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/)

```c++
class Solution {
public:

	int cuttingRope(int n) {
		if (n <= 1) {
			return 0;
		}
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        long res = 1;
        while(n > 4){
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }
        return (int)(res * n % 1000000007);
	}
};
```

---



