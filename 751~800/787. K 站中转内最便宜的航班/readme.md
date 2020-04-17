# 787. K 站中转内最便宜的航班

```c++
有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。 如果没有这样的路线，则输出 -1。

 

示例 1：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
城市航班图如下


从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
示例 2：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释: 
城市航班图如下


从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
 

提示：

n 范围是 [1, 100]，城市标签从 0 到 n - 1.
航班数量范围是 [0, n * (n - 1) / 2].
每个航班的格式 (src, dst, price).
每个航班的价格范围是 [1, 10000].
k 范围是 [0, n - 1].
航班没有重复，且不存在环路

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 动态规划方法（简化了的floyd 算法）

64 ms，此外，还可以使用回溯算法等等

```c++
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //dp[i][k]表示从src至多经过k站到达i的最少费用
        vector<vector<int>> dp(n, vector<int>(K + 2, 0x3f3f3f3f));
        //初始化 src 到 src的费用为0
        for (int k = 0; k <= K + 1; ++k){
            dp[src][k] = 0;
        }
        //开始动态规划
        for (int k = 1; k <= K + 1; ++k){
            for (auto &flight : flights){
                //从src至多经过k - 1站达flight[0]
                dp[flight[1]][k] = min(dp[flight[1]][k], dp[flight[0]][k - 1] + flight[2]);
            }
        }
        return dp[dst][K+1] >= 0x3f3f3f3f ? -1 : dp[dst][K+1];
    }
};
```

## 使用堆（类似于迪杰斯特拉算法）

来源[@fa-kuang-de-jie-zi](https://leetcode-cn.com/u/fa-kuang-de-jie-zi/)

```python
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        if src == dst: return 0
        graph = collections.defaultdict(dict)
        for start,end,cost in flights:
            graph[start][end] = cost

        queue = [(0,0,src)]
        while queue:
            cost, k, end = heapq.heappop(queue)
            if k > K+1 : continue
            if end == dst: return cost
            for key, val in graph[end].items():
                heapq.heappush(queue,(cost+val,k+1,key))
        return -1
```

---



