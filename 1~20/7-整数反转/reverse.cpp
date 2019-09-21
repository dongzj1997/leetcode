#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int ans = 0;
		int t1 = 0, t2 = 0;
		while (x != 0) {
			t1 = x % 10;
			x = x / 10;

			if (ans > 214748364 || (ans == 214748364 && t1 > 7))
				return 0;
			if (ans < -214748364 || (ans == -214748364  && t1 < -8))
				return 0;
			ans = ans * 10 + t1;
		}

		return ans;
	}
};


int main()
{
	//   2^31-1=2147483647,-2^31=-2147483648
	Solution s = Solution();
	int ans = s.reverse(-2147483647);
	cout << ans << endl;

	return 0;
}

/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

执行用时 :8 ms, 在所有 C++ 提交中击败了52.53%的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了95.14%的用户
时间复杂度O(log_10 N)空间复杂度O(1)


思路：对x每次对10求模，取余，关键是判断是否会溢出，如果ans的前几位大于214748364，此时还要*10 必定会溢出
如果刚好等于214748364，则判断最后一位是否大于或者小于2^31或者-2^31边界

*/