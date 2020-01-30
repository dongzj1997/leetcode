# 377. 组合总和 Ⅳ

```c++

```

---

## 第一版，记忆化递归

结果超时

最后执行的输入：
[3,33,333]  
10000

```c++
class Solution {
public:
	vector<int> dp;
	vector<int> nums;
	int combinationSum4(vector<int>& nums, int target) {
		dp = vector<int>(target+1, -1);
		dp[0] = 1;
		this->nums = nums;
		return helper(target);
	}
	int helper(int target) {
		if (target < 0)
			return 0;
		if (dp[target] > 0)
			return dp[target];


		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (target - nums[i] >= 0) {
				ans += helper(target - nums[i]);
			}
		}
		dp[target] = ans;
		return ans;
	}
};
```

---

## 第二版，动态规划，数组

使用unsigned int防止int越界报错。

```c++
class Solution {
public:
	

	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned int> dp(target + 1,0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int n : nums) {
				if ((i - n) >= 0 && dp[i - n] > 0) {
					dp[i] += dp[i - n];
				}
			}
		}
		return dp[target];
	}

};
```
---

如果数组中包涵负数，就和图的最短路径中包含负数一样处理。
