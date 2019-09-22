#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了99.81%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了92.18%的用户
*/

class Solution {
public:
	int romanToInt(string s) {//和上一题同理 使用贪心算法
		string A[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
		int B[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		int t = 12;
		int ans=0;
		while (s.length() > 0) {
			if (s.compare(0, A[t].length(), A[t]) == 0) {
				s = s.substr(A[t].length());
				ans += B[t];
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
	string input = "MCMXCIV";
	cout << s.romanToInt(input) << endl;
	return 0;
}