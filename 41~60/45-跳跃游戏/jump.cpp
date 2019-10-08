#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了86.52%的用户
内存消耗 :10.1 MB, 在所有 C++ 提交中击败了85.08%的用户
*/
/*
贪心算法，顺藤摸瓜，，，，，
*/
class Solution {
public:

	int jump(vector<int>& nums) {
		int len = nums.size() - 1;
		int steps = 0;
		int maxPosition = 0;  //下一步可以到达最远的位置
		int end = 0;  //当前步数可以到达最远的位置。



		for (int i = 0;i < len; i++) {
			maxPosition = max(maxPosition, nums[i] + i);
			if (i >= end) {
				end = maxPosition;
				steps++;
			}
		}
		return steps;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> input = { 0 };
	auto a = s.jump(input);

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}
	cout << a << endl;

	return 0;
}

