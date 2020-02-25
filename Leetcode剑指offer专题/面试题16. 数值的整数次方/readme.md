# 面试题16. 数值的整数次方

```c++
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

 

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

快速幂就是快

```c++
class Solution {
public:
	double myPow(double x, int n) {
		long n1 = n;
		bool flag = n1 < 0;
		if (n1 == 0)
			return 1.0;
		n1 = abs(n1);
		double t = x, ans = 1.0;
		while (n1 > 0) {
			if ((n1 & 1) == 1)
				ans *= t;
			n1 >>= 1;
			t = t * t;
		}

		return flag ? (1.0/ans) : ans;
	}
};
```

---



