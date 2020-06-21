# 1049. 最后一块石头的重量 II

```c++
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //其实就是求 从数组中挑出一些数字，使他们的和最接近总数组一半的问题。
        //经典的背包问题，如果sum不大的话，优先使用dp来做。
        int sum = 0, len = stones.size();
        for(int n:stones){
            sum += n;
        }
        vector<int> dp(sum/2 + 1,0); //dp[i] 表示总容量为i的情况下 可以装的最大值。
        for (int i = 0; i < len; i++){
            for (int j = sum/2 ; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[sum / 2];
    } 
};
```

---

