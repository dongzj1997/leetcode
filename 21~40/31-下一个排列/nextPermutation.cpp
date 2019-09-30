#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了97.74%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了99.44%的用户
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len == 1)
			return;
		int flag = -1;
		for (int i = len - 1; i > 0 ; i--) {
			if (nums[i] > nums[i - 1]) {
				flag = i - 1;
				break;
			}
		}
		
		if (flag == -1) {  //此时已经是最大排列，翻转整个数组使得排列变为最小。
			reverse(nums.begin(),nums.end());
			return;
		}
		int key = nums[flag];

		int b = flag + 1, e = len - 1,mid;
		while (true) {  //非典型的二分查找
			mid = (b + e)/2;
			if ((mid + 1) > (len - 1) || nums[mid] > key && nums[mid + 1] <= key  ) {
				break;
			}
			if (nums[mid] <= key) {
				e = mid;
			}
			else {
				b = mid+1;
			}
		}

		int t = nums[mid ];
		nums[mid] = key;
		nums[flag] = t;

		reverse(nums.begin() + flag +1 , nums.end());
	}
};

int main()
{
	Solution s = Solution();

	 
	vector<int> input = { 4,2,0,2,3,2,0 };
	//auto ans = s.nextPermutation(input);
	s.nextPermutation(input);
	                    
	for (int i : input) {
		cout << i << " , ";
	}
	//cout << ans << endl;

	return 0;
}
