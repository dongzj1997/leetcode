# 1029. 两地调度

```c++
公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。

返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

示例：

输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。

最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。

提示：

1 <= costs.length <= 100
costs.length 为偶数
1 <= costs[i][0], costs[i][1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-city-scheduling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## dp 方法

刚开始朝着dp方向想了一下，代码如下：

dp[i][j] 表示A地方去了i个人，B地去了j个人的最小容量

状态转移方程为`dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);`

```c++
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size()/2;
        int dp[100][100];
        for (int i = 1; i <= N; i++) {
            dp[i][0] = costs[i - 1][0] + dp[i - 1][0];
        }
        for (int j = 1; j <= N; j ++) {
            dp[0][j] = costs[j - 1][1] + dp[0][j - 1];
        }
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);
            }
        }

        return dp[N][N];
    }
};
```

## 贪心算法

退回去想一想发现使用贪心就可以解决这个问题。

其实一个人不是去A就是去B，最后答案是求最后累计的和。

那我们需要优化什么呢，优化又体现在哪里呢？

其实我们只要让A和B差异巨大的人先选A或者B就可以，所以先做一个排序，将A和B之差绝对值较大的靠前，让他先选。

选的时候要记录A和B此时个有多少人了，如果A满了，则后面的都去B，如果B满了，则后面的都去A

如果都没满，则选一个距离小的，同时将A或者B的计数器+1

```c++
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size() /2;
        sort(costs.begin(), costs.end(), [](vector<int> & a, vector<int> &b){
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
        }  );

        int cnt1 = 0, cnt2 = 0;
        int ans = 0;
        for(auto & cost : costs){
            if(cnt1 == N){
                ans += cost[1];
                cnt2++;
            }
            else if(cnt2 == N){
                ans += cost[0];
                cnt1++;
            }
            else{ //两队自由添加
                if(cost[0] < cost[1] ){
                    cnt1++;
                    ans += cost[0];
                }else{
                    cnt2++;
                    ans += cost[1];
                }
            }
        }
        return ans;
    }
};
```

## 贪心的另一种思路

[@harry](https://leetcode-cn.com/u/harry-63/)的解题：

先假设全部的人去A市，计算总和sum。 在分别计算 A - B的费用存入数组，由小到大排序，得到每个人去A 市比去B市多花的钱。 用sum 减去多花钱最多的前一般的钱数，即为最终最低总费用

```c++
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        // 计算全部去A的总和
        for (int i = 0; i < costs.size(); i++) {
            sum += costs[i][0];
        }
        // 选出一半的人去B， 意味着costs[i][0] - costs[i][1] 由大到小排序，前一半的人去B即可
        vector<int> arr;
        for (int i = 0; i < costs.size(); i++) {
            arr.push_back(costs[i][0] - costs[i][1]);
        }
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= arr.size() / 2; i--) {
            sum -= arr[i];
        }
        return sum;
    }
};
```

---
