#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ans = 1;
		if (nums.size() == 0)
			return 0;
		int t = nums[0];
		for (int e : nums) {
			if (e == t)
				continue;
			else {
				t = e;
				nums[ans] = e;
				ans++;
				
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();

	vector<int> input = { 1,1,3,4,5,6,7,7,8,9,9 };
	auto ans = s.removeDuplicates(input);

	cout << ans << endl;

	return 0;
}
