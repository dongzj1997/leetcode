#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

//出现重复元素时，直接和最后面的一个元素顶替，避免了频繁移动的问题。
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int len = nums.size();
		while (i < len) {
			if (nums[i] == val) {
				nums[i] = nums[len - 1];
				len--;
			}
			else {
				i++;
			}
		}
		return len;
	}
};


int main()
{
	Solution s = Solution();

	vector<int> input = { 1,1,3,4,5,6,7,7,8,9,9 };
	auto ans = s.removeElement(input,7);

	cout << ans << endl;

	return 0;
}
