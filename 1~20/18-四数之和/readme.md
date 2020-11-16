# 18. 四数之和

```c++
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (len < 4 ) {
			return ans;
		}
		for (int i = 0; i < len - 3; ) {
			

			for(int j = i + 1;j<len -2; ){
				int first = j + 1, last = len - 1;
				do {
					if (first >= last) 
						break; // 两人选相遇，则退出

					int result = nums[i] + nums[j] + nums[first] + nums[last];
					if (result == target) { // 如果可以组队
						ans.push_back({ nums[i] ,nums[j], nums[first] , nums[last] });
					}
					if (result <= target) { // 实力太弱，中间值边右移一位
						first++;
						while (first < last && nums[first] == nums[first - 1]) { first++; } // 如果相等就跳过
					}
					else { // 实力太强，把最右值那边右移一位
						last--;
						while (first < last && nums[last] == nums[last + 1]) { last--; }
					}
				} while (first < last);
				j++;
				while (j < (len - 2) && nums[j] == nums[j - 1]) { j++; }
			}
			i++;
			while (i < (len - 3) && nums[i] == nums[i - 1]) { i++; }
		}
		return ans;
	}
};
```

---
