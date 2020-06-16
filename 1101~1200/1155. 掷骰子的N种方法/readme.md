# 1155. 掷骰子的N种方法

```c++
这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。

我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。

如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。

 

示例 1：

输入：d = 1, f = 6, target = 3
输出：1
示例 2：

输入：d = 2, f = 6, target = 7
输出：6
示例 3：

输入：d = 2, f = 5, target = 10
输出：1
示例 4：

输入：d = 1, f = 2, target = 3
输出：0
示例 5：

输入：d = 30, f = 30, target = 500
输出：222616187
 

提示：

1 <= d, f <= 30
1 <= target <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这题和之前的零钱兑换比较像，不过比那道题简单，

主要是这题骰子是有编号的，先1 后2 和先2后1不一样（零钱那道题是一样的，所以更复杂一点）

所以这题直接相加就好。

```c++
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int M = 1e9+7;
        int dp[30][1005] = {0};
        for(int i=1;i<=f;i++){
            dp[0][i] = 1; //0号骰子，从1到f只有1中结果
        }
        for(int i=1;i<d;i++){ //1号到d-1号骰子
            for(int j=1;j<=f;j++){ // 该骰子的结果
                for(int k = j;k <= f*d; k++){ //最小到最大
                    dp[i][k] += dp[i-1][k-j];
                    dp[i][k] %= M;
                }
            }
        }
        return dp[d-1][target]% M;
    }
};
```

---

