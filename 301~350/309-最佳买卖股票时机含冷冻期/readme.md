# 309-最佳买卖股票时机含冷冻期

```c++
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用pre来记录前两天手上没股票时买入的值

```c++
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0; //当前的最大收益
        int i0 = 0, i1 = INT_MIN, pre = 0;
        for (int i = 0; i < prices.size(); i++) {
            int t= i0;
            i0 = max(i0, i1 + prices[i]);
            i1 = max(i1, pre - prices[i]);
            pre = t;

        }
        return i0;
	}
};
```

---



