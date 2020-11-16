# 29. 两数相除

```c++
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
 

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		bool sig = (dividend > 0 ) ^ (divisor > 0) ;  //亦或运算取得符号（其实不用加括号，为了取悦迎合编译器爹）
		long long dvd = llabs((long long)(dividend));  //这里偷个懒，不想判断溢出了,   !!!!!!abs只支持int类型，如果对long使用会出现bug，因该使用labs（还有cabs，fabs）
		//!!!!!!!!!!  亲测在64位win10 上long和labs也不好使，对 INT_MIN求labs时仍会错误，得使用long long 和llabs


		long long dvr = llabs((long long)(divisor));  //注意要先long long 再abs，
		int count = 0;
		long long ans = 0;

		while (dvd >= dvr) {
			dvr <<= 1; //左移，相当于*2
			count++;
		}

		while (count)
		{
			count -= 1;
			dvr >>= 1;
			if (dvd >= dvr) {
				ans += 1 << count;
				dvd -= dvr;
			}
		}
		if (ans == INT_MIN && dividend < 0 && divisor < 0) {
			return INT_MAX;
		}

		if (sig == 1) //为负数
			return (-1*ans) > INT_MIN ? (int)(-1*ans) : INT_MIN;
		else
			return ans > INT_MAX ? INT_MAX : (int)ans;
	}
};

int main()
{
	Solution s = Solution();

	 
	vector<int> input = { 1,1,3,4,5,6,7,7,8,9,9 };
	auto ans = s.divide(INT_MIN,-1);
	                    

	cout << ans << endl;

	return 0;
}

```

---
