# 122. 买卖股票的最佳时机 II

```c++
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		prices.push_back(-1);
		int ans = 0;
		int pre = prices[0];
		int buy = -1; //记录买的时候的股价
		for (int i = 1; i < prices.size(); i++) {
			if (pre > prices[i]) { //较昨天跌了
				if (buy >= 0) { //如果已经买了，赶紧时光倒流到昨天把股票买了
					ans += pre - buy;
					buy = -1;
				}
				else { //之前没买，赶紧时光倒流到昨天买一波
					;
				}
			}
			else if (pre < prices[i]) { //较昨天涨了
				if (buy >= 0) { //如果已经买了，就不做动作
					;
				}
				else { //之前没买，赶紧时光倒流到昨天买一波
					buy = pre;
				}
			}
			else { //股价持平，不做动作
				;
			}
			pre = prices[i];
		}
		return ans;
	}
};
```

---

时光倒流大法，穿越到明天看看涨跌来决定是否买卖股票。

## dp方法

```c++

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0; //当前的最大收益
		int i0 = 0, i1 =  INT_MIN; //当前的最小价格
        // i0是第i天没有股票的最大值， i1是第i天持有股票的最大值
		for (int i = 0; i < prices.size(); i++) {
            int t = i0;
			i0 = max(i0, i1 + prices[i]);
            i1 = max(i1, t - prices[i]);
		}
		return i0;
	}
};
```
