# 375. 猜数字大小 II

```c++
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

示例:

n = 10, 我选择了8.

第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

游戏结束。8 就是我选的数字。

你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

转载自[@SEU.FidGet](https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/comments/)

`dp[i][j]`表示从`[i,j]`中猜出正确数字所需要的最少花费金额.(`dp[i][i] = 0`)

假设在范围`[i,j]`中选择`x`, 则选择`x`的最少花费金额为: `max(dp[i][x-1], dp[x+1][j]) + x`

用`max`的原因是我们要计算最坏反馈情况下的最少花费金额(选了`x`之后, 正确数字落在花费更高的那侧)

初始化为`(n+2)*(n+2)`数组的原因: 处理边界情况更加容易, 例如对于求解`dp[1][n]`时`x`如果等于1, 需要考虑`dp[0][1]`(0不可能出现, `dp[0][n]`为0)

而当x等于n时, 需要考虑`dp[n+1][n+1]`(n+1也不可能出现, `dp[n+1][n+1]`为0)

如何写出相应的代码更新dp矩阵, 递推式`dp[i][j] = min(max(dp[i][x-1], dp[x+1][j]) + x), x~[i:j]`, 可以画出矩阵图协助理解, 可以发现
`dp[i][x-1]`始终在`dp[i][j]`的左部, `dp[x+1][j]`始终在`dp[i][j]`的下部, 所以更新dp矩阵时i的次序应当遵循bottom到top的规则, j则相反, 由于
i肯定小于等于j, 所以我们只需要遍历更新矩阵的一半即可(下半矩阵)


```c++
class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[i][j] = min(max(dp[i][x-1], dp[x+1][j]) + x), for x in range(i,j)
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int i=n;i>0;i--){
            for(int j=i+1;j< n+1; j++){
                dp[i][j]  = INT_MAX;
                for(int x =i; x <=j ;x++){
                    dp[i][j] = min(dp[i][j], max(dp[i][x-1], dp[x+1][j]) + x);
                }
            }
        }
        return dp[1][n];
    }
};
```

---



