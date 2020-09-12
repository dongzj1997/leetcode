# 1493. 删掉一个元素以后全为 1 的最长子数组

```c++
给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。

 

提示 1：

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。
示例 4：

输入：nums = [1,1,0,0,1,1,1,0,1]
输出：4
示例 5：

输入：nums = [0,0,0]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-subarray-of-1s-after-deleting-one-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

用两个变量，dp1 表示当前最长的连续1个数

dp2表示断之前，最长的连续1个数，最后的总长度是两者之和。

注意题目要求最少删一个，所以要判断序列是否全为1.

```c++
class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int len = nums.size();
		int dp1 = 0, dp2 = 0, ans = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i]) {
				dp1++;
			}
			else {
				dp2 = dp1;
				dp1 = 0;
			}
			ans = max(ans, dp1 +  dp2);
		}
		return ans == len ? ans-1 : ans;
	}
};
```

---
