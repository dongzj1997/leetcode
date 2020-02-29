# 面试题43. 1～n整数中1出现的次数

```c++
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31
注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

各位上分别统计，信手拈来

```c++
class Solution {
public:
	int countDigitOne(int n) {
		long high,low,now ,i=1;
		long ans =0;
		while (i<=n) {
			high = n / (i*10);
			low = n % i;
			now = (n / i) % 10;

			if(now ==0)
				ans = ans + high * i ;
			if(now == 1)
				ans = ans + high * i + low + 1;
			if(now > 1)
				ans = ans + (high+1) * i;

			i *= 10;
		}
		return (int)ans;
	}
};

```

---



