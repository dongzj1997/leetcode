# 1563. 石子游戏 V

```c++
几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出。

游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。

只 剩下一块石子 时，游戏结束。Alice 的分数最初为 0 。

返回 Alice 能够获得的最大分数 。

 

示例 1：

输入：stoneValue = [6,2,3,4,5,5]
输出：18
解释：在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
示例 2：

输入：stoneValue = [7,7,7,7,7,7,7]
输出：28
示例 3：

输入：stoneValue = [4]
输出：0
 

提示：

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-v
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

算是一道比较常规的的区间dp题。

ps，讨论区反映，好像这道题用递归做反而比建一个dp数组，然后循环的方法快，估计是递归可以避免不少没必要的计算吧。

```c++
class Solution {
public:
    int dp[501][501];
    int sum[501]; //前缀和

    int helper(int L, int R) {
        if (dp[L][R] != -1) { 
            return dp[L][R];
        }
        if (L == R) { // 终止条件，直接获得答案
            dp[L][R] = 0;
        }
        else {
            //递进阶段，根据题意，求解最大值；
            int ans = 0;
            for (int i = L; i < R; i++) {
                int s1 = sum[i] - sum[L - 1];
                int s2 = sum[R] - sum[i];

                if (s1 < s2) { // 取后半段
                    ans = max(ans, s1 + helper(L, i));
                }
                else if (s1 > s2) { // 取前半段
                    ans = max(ans, s2 + helper(i + 1, R));
                }
                else { // 取左右的最大值
                    ans = max(ans, max(helper(L, i), helper(i + 1, R)) + s1);
                }
            }
            dp[L][R] = ans;
        }
        return dp[L][R];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int len = stoneValue.size();
        memset(dp, -1, sizeof(dp));

        //前缀和数组的初始化
        sum[0] = 0;
        for (int i = 0; i < len; i++) {
            sum[i + 1] = sum[i] + stoneValue[i];
        }
        // 注意是从1开始，到len结束
        return helper(1, len);
    }
};
```

---
