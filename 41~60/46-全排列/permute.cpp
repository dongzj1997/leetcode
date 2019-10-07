#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
执行用时 :8 ms, 在所有 C++ 提交中击败了99.92%的用户
内存消耗 :9.4 MB, 在所有 C++ 提交中击败了57.49%的用户
*/
class Solution {
public:

	vector<vector<int>> ans;
	int len;
	vector<int> nums;
	vector<vector<int>> permute(vector<int>& nums) {
		this->len = nums.size();
		this->nums = nums;

		Recursive(0);
		return this->ans;
	}

	void Recursive(int deep) {
		if (deep == len-1) {
			ans.push_back(nums);
		}
		
		for (int i = deep; i < len; i++) {
			//交换
			int t = nums[i]; 
			nums[i] = nums[deep];
			nums[deep] = t;

			Recursive(deep+1);

			//交换回来
			nums[deep] = nums[i];
			nums[i] = t;

		}

	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 1 };
	auto a = s.permute(input);

	for (auto t : a) {
		for (auto tt : t) {
			cout << tt << " , ";
		}
		cout << endl;
	}
	//cout << a << endl;

	return 0;
}

