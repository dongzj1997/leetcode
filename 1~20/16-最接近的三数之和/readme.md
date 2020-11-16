# 16. 最接近的三数之和

```c++
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
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
```

---
