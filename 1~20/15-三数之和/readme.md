# 15. 三数之和

```c++
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if ( len < 3 || nums[0]>0 || nums[len - 1] < 0) {
			return ans;
		}
		for (int i = 0; i < len-2; ) {
			if (nums[i] > 0) break; // 最左值为正数则一定无解
			int first = i + 1, last = len - 1;
			do {
				if (first >= last || nums[i] <0 && nums[last] < 0 || nums[i] > 0 && nums[last] >0) //如果 nums[i] * nums[last] >  可能会溢出
					break; // 两人选相遇，或者三人同符号，则退出

				int result = nums[i] + nums[first] + nums[last];
				if (result == 0) { // 如果可以组队
					ans.push_back({ nums[i] , nums[first] , nums[last] });
				}
				if (result <= 0) { // 实力太弱，中间值边右移一位
					first++;
					while (first < last && nums[first] == nums[first - 1]) { first++; } // 如果相等就跳过
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
	vector<int> input = { -1, 0, 1, 2, -1, -4 };
	auto a = s.threeSum(input);
	for (auto s : a) {
		for (auto b : s) {
			cout << b << " ";
		}
		cout << endl;
	}
	//cout << s.longestCommonPrefix(input) << endl;
	return 0;
}
```

---
