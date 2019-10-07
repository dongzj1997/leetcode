#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int max_left = 0;
		int max_right = 0;
		int left = 1;    //去头去尾
		int right = height.size() - 2; // 加右指针进去

		/*
		假设一开始left-1大于right+1，则之后right会一直向左移动，直到right+1大于left-1。
		在这段时间内right所遍历的所有点都是左侧最高点maxleft大于右侧最高点maxright的，所以只需要根据原则判断maxright与当前高度的关系就行。反之left右移，
		所经过的点只要判断maxleft与当前高度的关系就行。
		*/
		while (left <= right) {
			if (height[left - 1] < height[right + 1]) {  //右边大于左边，应该 左指针 向右移动一个单位
				max_left = max(max_left, height[left - 1]);
				if (max_left > height[left]) {  //如果当前左值小于最大的左值，说明可以接到雨水
					ans += (max_left - height[left]);//可以接到多少雨水
				}
				left++;
			}
			else {
				max_right = max(max_right, height[right + 1]);
				if (max_right > height[right]) {
					ans += (max_right - height[right]);
				}
				right--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	auto a = s.trap(input);
	cout << a << endl;

	return 0;
}

