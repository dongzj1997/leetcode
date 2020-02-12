# 486-预测赢家

```c++
给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

示例 1:

输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。
示例 2:

输入: [1, 5, 233, 7]
输出: True
解释: 玩家1一开始选择1。然后玩家2必须从5和7中进行选择。无论玩家2选择了哪个，玩家1都可以选择233。
最终，玩家1（234分）比玩家2（12分）获得更多的分数，所以返回 True，表示玩家1可以成为赢家。
注意:

1 <= 给定的数组长度 <= 20.
数组里所有分数都为非负数且不会大于10000000。
如果最终两个玩家的分数相等，那么玩家1仍为赢家。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/predict-the-winner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		// 模拟真实情况下，A，B轮流选牌的过程，求出结果

		return helper(0, nums.size() - 1, 0, 0, true, nums);
	}

	//分别为  左边可取的位置，右边可取的位置，A的得分，B的得分，   轮到谁选牌，   nums数组
	bool helper(int left, int right, int score_A, int score_B, bool turn_to_A, vector<int>& nums) {
		if (left > right) //左右越界，没有牌了，比较得分，判断胜负（以A为主角）
			return score_A >= score_B;
		if (turn_to_A) //轮到A选牌,A是主角，只要左边或者右边有一种必胜情况，就说明可以必胜
			return helper(left + 1, right, score_A + nums[left], score_B, false, nums) || helper(left, right - 1, score_A + nums[right], score_B, false, nums);
		else //轮到B选牌，不管B怎么选，此时只有左右两边都保证A是必胜的，才能保证A最终必胜！
			return helper(left + 1, right, score_A, score_B + nums[left], true, nums) && helper(left, right - 1, score_A, score_B + nums[right], true, nums);
	}
};
```

---

## 动态规划解法

来自 Leetcode官方

我们同样可以使用动态规划来解决这个问题。用`dp(i, j)`表示当剩下的数为`nums[i .. j]`时，当前操作的选手（注意，不一定是先手）与另一位选手最多的分数差。当前操作的选手可以选择 `nums[i]` 并留下`nums[i+1 .. j]`，或选择 `nums[j]` 并留下 `nums[i .. j-1]`，因此状态转移方程为：

```c++
dp(i, j) = max(nums[i] - dp(i+1, j), nums[j] - dp(i, j-1))
dp(i, i) = nums[i]
如果 dp(0, n - 1) >= 0，那么先手必胜。
```

```java
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length + 1][nums.length];
        for (int s = nums.length; s >= 0; s--) {
            for (int e = s + 1; e < nums.length; e++) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = Math.max(a, b);
            }
        }
        return dp[0][nums.length - 1] >= 0;
    }
}

```
