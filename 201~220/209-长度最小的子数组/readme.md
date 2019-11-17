# 209. 长度最小的子数组

```c++
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题：使用滑动窗口

详细过程已经写在注释中。


```c++
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ans = INT_MAX;
		int i = 0; //滑窗的右边框
		int sum = 0; //窗口间的和
		int begin = 0; //滑窗的左边框
		while (i < nums.size()) { //滑窗的右边框不能超出界限
			if (sum + nums[i] < s) { //若滑窗之间的和小于s，右边框右移，sum增大
				sum += nums[i];
				i++;
			}
			else {              //和大于等于s，左边框右移，sum减小
				if (i - begin < ans) //若当前符合条件的连续子数组比ans内记录的长度更小，则更新ans值
					ans = i - begin + 1;
				sum -= nums[begin];
				begin++;
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};
```
