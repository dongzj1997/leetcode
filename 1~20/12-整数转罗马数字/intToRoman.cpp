#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	string intToRoman(int num) {
		string A[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
		int B[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		string ans = "";
		int t = 12;
		while (num > 0) {
			if (num >= B[t]) {
				num -= B[t];
				ans += A[t];
			}
			else {
				t--;
			}
		}
		return ans;
	}
};
int main()
{
	Solution s = Solution();
	int input = 58;
	cout << s.intToRoman(input) << endl;
	return 0;
}