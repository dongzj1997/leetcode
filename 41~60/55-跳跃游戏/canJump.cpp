#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了86.12%的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了94.65%的用户
*/
class Solution {
public:

	bool canJump(vector<int>& nums) {
		int len = nums.size() - 1;
		if (len == 0) {
			return 1;
		}
		int max = 0;
		for (int i = 0;i<=max && i < len; i++) {
			max = max > i + nums[i] ? max : i + nums[i];
			if (max >= len) {
				return 1;
			}
		}
		return 0;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> input = { 0 };
	auto a = s.canJump(input);

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}
	cout << a << endl;

	return 0;
}

