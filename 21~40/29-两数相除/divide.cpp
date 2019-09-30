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
