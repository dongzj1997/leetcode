# 790. 多米诺和托米诺平铺

```c++
有两种形状的瓷砖：一种是 2x1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。

XX  <- 多米诺

XX  <- "L" 托米诺
X
给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。

（平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。）

示例:
输入: 3
输出: 5
解释: 
下面列出了五种不同的方法，不同字母代表不同瓷砖：
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
提示：

N  的范围是 [1, 1000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/domino-and-tromino-tiling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

基本的动态规划

```c++
class Solution {
public:
    int numTilings(int N) {
        int MOD=1000000007;
        if(N == 1) return 1;
        vector<vector<long>>dp(N,vector<long>(3));
        dp[0]=vector<long>{0,0,1};
        dp[1]=vector<long>{1,1,2};
        for(int i=2;i<N;i++){
            dp[i][0]=(dp[i-1][1]+dp[i-2][2])%MOD; //上多一块
            dp[i][1]=(dp[i-1][0]+dp[i-2][2])%MOD;// 下多一块
            dp[i][2]=(dp[i-1][2]+dp[i-2][2]+dp[i-1][0]+dp[i-1][1])%MOD; //不多不少
        }
        return dp[N-1][2];
    }
};
```

---



