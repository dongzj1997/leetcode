#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了85.67%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了82.85%的用户
*/

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//int ans = 0;
		int len = nums.size();
		for (int i=0; i < len;i++ ) {
			if (nums[i] != i+1 && nums[i]>0 && nums[i] <= len) {  //输入数组的第i个位置，该位置上的值有效  (如果位置合适，直接判断下一位)
				int t = nums[nums[i] - 1]; //这个数本来应该在的位置当前的数为t
				if (t == nums[i])
					continue;  //如果已经归位，则不交换，继续
				nums[nums[i] - 1] = nums[i];
				nums[i] = t;
				i--;
			}
		}
		int i = 0;
		for (; i < len; i++) {
			if (nums[i] != i + 1) {
				break;
			}

		}
		return i+1;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 1,1,};
	auto a = s.firstMissingPositive(input);
	cout << a << endl;

	return 0;
}