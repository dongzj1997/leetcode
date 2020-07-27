# 1000. 合并石头的最低成本

```c++
有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。

每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。

找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。

 

示例 1：

输入：stones = [3,2,4,1], K = 2
输出：20
解释：
从 [3, 2, 4, 1] 开始。
合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
合并 [4, 1]，成本为 5，剩下 [5, 5]。
合并 [5, 5]，成本为 10，剩下 [10]。
总成本 20，这是可能的最小值。
示例 2：

输入：stones = [3,2,4,1], K = 3
输出：-1
解释：任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
示例 3：

输入：stones = [3,5,1,2,6], K = 3
输出：25
解释：
从 [3, 5, 1, 2, 6] 开始。
合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
合并 [3, 8, 6]，成本为 17，剩下 [17]。
总成本 25，这是可能的最小值。
 

提示：

1 <= stones.length <= 30
2 <= K <= 30
1 <= stones[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-merge-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

四维的区间dp，自从戳气球和奇怪的打印机之后见过的又一dp难题，感觉是very hard

难啊马飞

```c++
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {

        int len = stones.size();
        if ((len - 1) % (K - 1) != 0) return -1; //先判断是否有解

        vector<int> prefix(len + 1, 0); //存储前缀和
        for (int i = 1; i <= len; i++) {
            prefix[i] = prefix[i-1] + stones[i-1];
        }

        //vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(len + 1, vector<int>(K + 1, 0x3f3f3f3f))); //最后一个K 表示要将区间内的石子压缩为 k 个
        int dp[31][31][31];
        memset(dp, 0x3f, sizeof(dp));
        // dp[i][j][k] 表示从i开始到j结尾（包含i，j），每次合并为k个 所用的最小成本
        for (int i = 0; i <= len; i++) dp[i][i][1] = 0; // 对于长度为1的 左闭右闭 区间，值为0

        for (int l = 2; l <= len; l++) { //区间长度
            for (int i = 0; i + l <= len; i++) {//区间起始点
                int j = i + l - 1; //区间终止点 （j < len）
                for (int k = 2; k <= K; k++) { //尝试将i到j的石子合并为k堆 （每次将大K个合并为1个），k和K没有什么关系，
                    //for (int m = i; m < j; m += K -1) 也可以
                    for (int m = i; m < j; m +=1) { // 将m前面的合并为一堆，m后面的合并为k-1堆
                        dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                    }
                    //不管k怎么变，最后合并为总的一定是不变的，所以我们可以找一个最小的dp[i][j][k]加上综合就是合并为1堆的答案
                    dp[i][j][1] = (prefix[j + 1] - prefix[i]) + dp[i][j][k];
                }

            }

        }
        return dp[0][len - 1][1];
    }
};
```

---
