# 903. DI 序列的有效排列

```c++
903. DI 序列的有效排列
我们给出 S，一个源于 {'D', 'I'} 的长度为 n 的字符串 。（这些字母代表 “减少” 和 “增加”。）
有效排列 是对整数 {0, 1, ..., n} 的一个排列 P[0], P[1], ..., P[n]，使得对所有的 i：

如果 S[i] == 'D'，那么 P[i] > P[i+1]，以及；
如果 S[i] == 'I'，那么 P[i] < P[i+1]。
有多少个有效排列？因为答案可能很大，所以请返回你的答案模 10^9 + 7.

 

示例：

输入："DID"
输出：5
解释：
(0, 1, 2, 3) 的五个有效排列是：
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 

提示：

1 <= S.length <= 200
S 仅由集合 {'D', 'I'} 中的字符组成
```

---

太难了，这道题我不会做（此处应有袁华的BGM）

// k=j; 这个地方我理解了有一小时

```c++
class Solution {
public:
    int numPermsDISequence(string S) {
        int M = 1e9+7;
        int len = S.size();
        int dp[205][205] = {0};
        dp[0][0] = 1;
        for(int i=1;i<=len;i++){
            for(int j=0;j<=i;j++){
                if(S[i-1] == 'D'){
                    for(int k=j;k<i;k++){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= M;
                    }
                }
                else{
                    for(int k=0;k<j;k++){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= M;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<205;i++){
            ans += dp[len][i];
            ans %= M;
        }
        return ans;
    }
};
```

---
