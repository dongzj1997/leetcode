# 188-买卖股票的最佳时机 IV

```c++
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

如果交易次数k很大，就相当于是无限次交易了

```c++
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int ans = 0; //当前的最大收益
        if (k > prices.size() / 2) {
            int i0=0, i1 = INT_MIN;
            for (int i = 0; i < prices.size(); i++) {
                int t= i0;
                i0 = max(i0, i1 + prices[i]);
                i1 = max(i1, t - prices[i]);

            }
            return i0;
        }

            
            
		vector<int> i0(k+1, 0), i1(k+1, INT_MIN); //当前的最小价格
        // i0是第i天没有股票的最大值， i1是第i天持有股票的最大值
		for (int i = 0; i < prices.size(); i++) {
            for(int j=1;j<=k;j++){
                i0[j] = max(i0[j], i1[j] + prices[i]);
                i1[j] = max(i1[j], i0[j-1] - prices[i]);
            }

		}
		return i0[k];
	}
};
```

---



