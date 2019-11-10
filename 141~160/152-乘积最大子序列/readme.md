# 152. 乘积最大子序列

```c++
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int a = 1, b = 1; //分别保存之前遍历到的最小值和最大值
		int ans = INT_MIN;

		for (int i = 0; i < nums.size(); i++) {

			int aa = a * nums[i];
			int bb = b * nums[i];

			a = min(nums[i], min(aa, bb));  //一般为负数
			b = max(nums[i], max(aa, bb));

			ans = max(ans, b);
		}
		return ans;
	}
};
```

---

考虑到负负得正的情况，动态规划保存之前乘积的最大值和最小值，和本元素相乘以后再更新最大值和最小值。
