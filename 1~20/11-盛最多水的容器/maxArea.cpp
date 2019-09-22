#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {   //典型的贪心算法，可以看做从两边向中间靠拢，不断的削掉某一侧，肯定选择短的削掉，因为短的可能包含的最优解长的一定包含。
		int left = 0, right = height.size()-1;
		int ans = 0;
		int area = 0;
		while (left != right) {
			area = min(height[left], height[right]) * (right - left);
			ans = area > ans ? area : ans;
			if (height[left] > height[right]) {
				right--;
			}
			else {
				left++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input({ 1,8,6,2,5,4,8,3,7 });
	int ans = s.maxArea(input);
	cout << ans << endl;
	return 0;
}