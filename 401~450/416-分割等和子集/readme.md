# 416-分割等和子集

```c++
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

动态规划方法求解o-1背包问题。

本来的dp数组是一个`nums.size()` 行，`目标货物总重量`为列数的表格，但是由于每一次动态规划的时候至于上一层的值有关，所以可以将这个表格缩减。

状态转移的方程为`dp[s] = dp[s] || dp[s - nums[i]];`

```c++
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int t : nums) 
			sum += t;
		if (sum & 1) //为奇数，比不可能等分
			return false;
		sum /= 2;
		vector<bool> dp(sum + 1, false);

		dp[0] = true;
		if (nums[0] <= sum) {
			dp[nums[0]] = true;
		}

		for (int i = 1; i < nums.size(); i++) {
			for (int s = sum; s >= nums[i]; s--) {
					dp[s] = dp[s] || dp[s - nums[i]]; //该值取决于选或不选
			}
			if (dp[sum])
				return true;
		}
		return dp[sum];
	}
};
```

---

## 解法2 回溯

普通的回溯我就不写了，但是在解题区看到一个`两头剪枝`的方法

不管是选择的太多了或者是丢弃的太多了都不行,

记得先排序，这样在回溯的过程中容易触发剪枝条件，挺有意思的。

代码:

```java

class Solution {
    public boolean canPartition(int[] nums) {
        //涉及到剪枝的问题，先排个序
        Arrays.sort(nums);
        int sum = 0;
        //算出SUM(S)
        for (int n : nums){
            sum += n;
        }
        //奇数肯定不行
        if ((sum & 1) == 1){
            return false;
        }
        sum >>= 1;
        //搜索
        return canPartition(nums, nums.length-1, sum, sum);
    }

    //DFS idx为当前元素，had为待接受上限，pass为待丢弃上限
    private boolean canPartition(int[] nums, int idx, int had, int pass){
        //找到可行解
        if (had == 0 || pass == 0){
            return true;
        }
        //剪枝
        else if (had < 0 || pass < 0){
            return false;
        }
        //继续搜索
        else{
            return canPartition(nums, idx-1, had-nums[idx], pass) || canPartition(nums, idx-1, had, pass-nums[idx]);
        }
    }
}
/*
作者：lava-4
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/java-dfsjian-zhi-1ms-9931-by-lava-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```

