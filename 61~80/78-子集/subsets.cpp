#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	int len = 0;
	vector<int> t;
	vector<vector<int>> subsets(vector<int>& nums) {
		len = nums.size();
		dfs(0, nums);
		return ans;
	}
	void dfs(int deep, vector<int>& nums) {
		if (deep == len)
			ans.push_back(t);
		else {
			dfs(deep + 1, nums); //不pick

			t.push_back(nums[deep]); //pick
			dfs(deep + 1, nums);
			t.pop_back();
		}
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = {   } ;
	auto a = s.subsets(input);

	for (auto t : a) {
		for (auto tt : t) {
			cout << tt << " , ";
		}
		cout << endl;
	}
	//cout << a << endl;

	return 0;
}

