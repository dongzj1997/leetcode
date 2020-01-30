# 357-计算各个位数不同的数字个数

```c++
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。

示例:

输入: 2
输出: 91 
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

找规律：

f(0) = 1

f(1) = 10 = 9 + 1

f(2) = 9 * 9 + 10 = 91

f(3) = 9 * 9 * 8 + 91 = 739

f(4) = 9 * 9 * 8 * 7 + 739 

```c++
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;

		int ans = 10;
		int t=9;
		n = min(n, 10);

		for (int i = 1; i < n; i++) {
			t *= 10 - i;
			ans += t;
		}
		return ans;
	}
};
```

---



