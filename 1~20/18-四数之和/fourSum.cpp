#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (len < 4 ) {
			return ans;
		}
		for (int i = 0; i < len - 3; ) {
			//if (nums[i] > target) break; // 最左值大于target则一定无解

			for(int j = i + 1;j<len -2; ){
				int first = j + 1, last = len - 1;
				do {
					if (first >= last) 
						break; // 两人选相遇，则退出

					int result = nums[i] + nums[j] + nums[first] + nums[last];
					if (result == target) { // 如果可以组队
						ans.push_back({ nums[i] ,nums[j], nums[first] , nums[last] });
					}
					if (result <= target) { // 实力太弱，中间值边右移一位
						first++;
						while (first < last && nums[first] == nums[first - 1]) { first++; } // 如果相等就跳过
					}
					else { // 实力太强，把最右值那边右移一位
						last--;
						while (first < last && nums[last] == nums[last + 1]) { last--; }
					}
				} while (first < last);
				j++;
				while (j < (len - 2) && nums[j] == nums[j - 1]) { j++; }
			}
			i++;
			while (i < (len - 3) && nums[i] == nums[i - 1]) { i++; }
		}
		return ans;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> input = { 1,-2,-5,-4,-3,3,3,5 };
	auto a = s.fourSum(input,-11);
	for (auto s : a) {
		for (auto b : s) {
			cout << b << " ";
		}
		cout << endl;
	}
	//cout << s.longestCommonPrefix(input) << endl;
	return 0;
}