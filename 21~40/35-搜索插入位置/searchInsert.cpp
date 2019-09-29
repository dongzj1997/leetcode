#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1;
		int mid=0;

		if (nums[right] < target) {
			return right + 1;
		}

		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] > target) {
				right = mid ;
			}
			else {
				left = mid + 1;
			}
			if (left == right) {
				return left;
			}
		}
		return mid;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 4,5,7,8};
	auto a = s.searchInsert(input,9);
	cout << a << endl;
	return 0;
}