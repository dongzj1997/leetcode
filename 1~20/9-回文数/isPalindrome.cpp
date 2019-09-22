#include<iostream>

using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		int t = 0;
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		while (x > t) {
			t = 10 * t + x % 10;
			x = x / 10;
		}
		return x == t || x == t / 10;  //表示如果是奇数，则最后一位不比较，如果是偶数，则判断是否相等
	}
};

int main()
{
	Solution s = Solution();
	bool ans = s.isPalindrome(123321);
	cout << ans << endl;
	return 0;
}