# 494. 目标和

```c++
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1：递归

```c++
class Solution {
public:
	int ans = 0;
	int n = 0;
	int findTargetSumWays(vector<int>& nums, int S) {
		
		n = nums.size();

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += abs(nums[i]);
		if (sum < S)
			return 0;
		helper(0, nums, S);
		return ans;
	}
	void helper(int index, vector<int>& nums, int rest) {
		if (index == n) {
			if (rest == 0)
				ans++;
			return;
		}
		helper(index+1, nums, rest + nums[index]);
		helper(index+1, nums, rest - nums[index]);

	}
};
```

---

## 解法2：问题转换+动态规划

来自评论区的[@16281065](https://leetcode-cn.com/u/16281065/)

原问题等同于： 找到nums一个正子集和一个负子集，使得总和等于target

我们假设P是正子集，N是负子集 例如： 假设nums = [1, 2, 3, 4, 5]，target = 3，一个可能的解决方案是+1-2+3-4+5 = 3 这里正子集P = [1, 3, 5]和负子集N = [2, 4]

那么让我们看看如何将其转换为子集求和问题：


```c++

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
```

因此，原来的问题已转化为一个求子集的和问题： 找到nums的一个子集 P，使得sum(P) = (target + sum(nums)) / 2

请注意，上面的公式已经证明target + sum(nums)必须是偶数，否则输出为0 java代码示例：

```java
        int sum = 0;
        for (int n : nums)
            sum += n;
        return sum < s || (s + sum) % 2 > 0 ? 0 : subsetSum(nums, (s + sum) >>> 1); 
    }   

    public int subsetSum(int[] nums, int s) {
        int[] dp = new int[s + 1]; 
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n]; 
        return dp[s];
```

这个代码是之前使用动态规划解决0-1背包问题的现成代码。