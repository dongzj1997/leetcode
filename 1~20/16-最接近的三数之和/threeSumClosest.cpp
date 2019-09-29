#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//没什么难度，，注意返回的是距离还是三者之和

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int near = INT_MAX; //当前最近距离
		int ans = INT_MAX;
		int len = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len - 2; ) {
			int first = i + 1, last = len - 1;
			do {
				int result = nums[i] + nums[first] + nums[last];
				if (near > abs(target - result)) {
					near = abs(target - result);
					ans = result;
				}
				if (result == target) {
					return result;
				}
				if (result < target) { // 实力太弱，中间值边右移一位
					first++;
					while (first < last && nums[first] == nums[first - 1]) { first++; }
				}
				else { // 实力太强，把最右值那边右移一位
					last--;
					while (first < last && nums[last] == nums[last + 1]) { last--; }
				}
			} while (first < last);
			i++;
			while (i < (len - 2) && nums[i] == nums[i - 1]) { i++; }
		}
		return ans;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> input = { 0,1,2 };
	auto a = s.threeSumClosest(input,3);
	cout << a << endl;
	return 0;
}