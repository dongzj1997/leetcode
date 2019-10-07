#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
使用循环实现快速幂
原理：x^b   将b记为2进制数， 如x^101010 可以表示为x^100000 * x^1000 * x^10 ，而x^n可以不用重复计算，自底向上 x^100 = x^10 *x^10
免去了很多无用的计算

*/
class Solution {
public:

	double qpow(double a, long long b) {
		double res = 1;
		while (b) {
			if (b & 1) res = res * a;
			b >>= 1;
			a *= a;
		}
		return res;
	}


	double myPow(double x, long long n) {
		if (n == 0) return 1;
		if (n > 0) return qpow(x, n);
		if (n < 0) return 1 / qpow(x, -n);
	}
};

/*
class Solution {
public:
	//递归方法
	double myPow(double x, int n) {
		long long N = n;//n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。,防止最小的负数变正数以后溢出
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		return Pow(x, N);
	}

	double Pow(double x, long long n) {
		
		if (n == 0) {
			return 1;
		}
		if (n == 1) {
			return x;
		}

		if (n % 2 == 0) {
			double t = myPow(x, n / 2);
			return t * t;
		}
		else {
			double t = myPow(x, n / 2);
			return t * t * x;
		}
	}
};
*/
int main()
{
	Solution s = Solution();
	vector<vector<int>> input = { {1,2,3},{4,5,6},{7,8,9} };
	auto a = s.myPow(2.0000, -2147483647-1);


	cout << a << endl;

	return 0;
}

