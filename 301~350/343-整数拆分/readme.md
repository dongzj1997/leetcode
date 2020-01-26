# 343. 整数拆分

```c++
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1 动态规划

简单的动态规划，没什么好讲。

需要注意的一点是对于前几个数直接相乘得到的值更大（如f(5) = 6 (2 *3)）

所以要加一行`dp[i] = max(dp[i], j *(i-j));`

或者写成`dp[2]=2;  dp[3]=3;  dp[i]=Math.max(dp[i],dp[j]*dp[i-j]);` ,然后对`n=2 n=3`进行单独讨论

```c++

class Solution {
public:

	int integerBreak(int n) {
		vector<int> dp(n+1, 0);
		if (n <= 1) {
			return 0;
		}
		dp[2] = 1;
		

		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				dp[i] = max(dp[i], j *(i-j));
				dp[i] = max(dp[i], j * dp[i - j]);
			}
		}

		return dp[n];
	}
};
```

---

## 解法2 数学推导

数学方法，求函数y=(n/x)^x(x>0)的最大值，可得x=e时y最大，但只能分解成整数，故x取2或3，由于6=2+2+2=3+3，显然2^3=8<9=3^2,故应分解为多个3



```c++
int integerBreak(int n) {
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    int a = 1;
    while(n > 4){
        n = n - 3;
        a = a * 3;
    }
    return a * n;
}
```

