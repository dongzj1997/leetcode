# 1499. 满足不等式的最大值

```c++
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。

 

示例 1：

输入：points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
输出：4
解释：前两个点满足 |xi - xj| <= 1 ，代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。
示例 2：

输入：points = [[0,0],[3,0],[9,2]], k = 3
输出：3
解释：只有前两个点满足 |xi - xj| <= 3 ，代入方程后得到值 0 + 0 + |0 - 3| = 3 。
 

提示：

2 <= points.length <= 10^5
points[i].length == 2
-10^8 <= points[i][0], points[i][1] <= 10^8
0 <= k <= 2 * 10^8
对于所有的1 <= i < j <= points.length ，points[i][0] < points[j][0] 都成立。也就是说，xi 是严格递增的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-value-of-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

单调栈的题

这里贴一个别人的代码，写的真是清晰。

来自[@liuyubobobo](https://leetcode-cn.com/problems/max-value-of-equation/solution/xian-duan-shu-you-xian-dui-lie-hong-hei-shu-san-ch/)

```c++
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        deque<pair<int, int>> dq;
        dq.push_front({ points[0][1] - points[0][0], points[0][0] });
        int ans = INT_MIN;
        for (int i = 1; i < points.size(); i++) {

            // 对队列首不符合约束的点删除
            while (!dq.empty() && points[i][0] - dq.front().second > k)
                dq.pop_front();

            // 根据队首最大元素信息更新解
            if (!dq.empty())
                ans = max(ans, points[i][1] + points[i][0] + dq.front().first);

            // 把队列尾的比当前 y - x 还小的元素删除
            while (!dq.empty() && dq.back().first <= points[i][1] - points[i][0])
                dq.pop_back();

            // 将当前点的信息加入队列
            dq.push_back({ points[i][1] - points[i][0], points[i][0] });
        }
        return ans;
    }
};
```

---
