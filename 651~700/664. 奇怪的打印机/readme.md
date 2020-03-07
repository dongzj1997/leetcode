# 664. 奇怪的打印机

```c++

有台奇怪的打印机有以下两个特殊要求：

打印机每次只能打印同一个字符序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给定一个只包含小写英文字母的字符串，你的任务是计算这个打印机打印它需要的最少次数。

示例 1:

输入: "aaabbb"
输出: 2
解释: 首先打印 "aaa" 然后打印 "bbb"。
示例 2:

输入: "aba"
输出: 2
解释: 首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
提示: 输入字符串的长度不会超过 100。
```

---

这道题其实是[546. 移除盒子](https://leetcode-cn.com/problems/remove-boxes/)的简化版。

移除盒子计算的是最大积分，而此题计算的是一共需要几次可以完全消除（打印出来）。

其实每计算一次积分就等于打印一次，将上题计算积分处改为打印一次，然后将最大值函数改为最小值函数即可。



接迭代版：

```c++
class Solution {
public:
    int strangePrinter(string s) {
        int dp[100][100] = {0};
        int len = s.size();
        if(len == 0) return 0;
        for(int i=0;i<len;i++)
            dp[i][i] = 1;
        
        for(int l = 1;l<len;l++){//区间长度
            for(int j = l; j < len; j++){
                int i = j-l;
                dp[i][j] = 1 + dp[i+1][j];
                for(int k = i+1;k<=j;k++){
                    if(s[i] == s[k])
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                }
            }
        }
        return dp[0][len-1];
    }
};
```

---

递归版

```c++
class Solution {
public:
    int strangePrinter(string s) {
        int dp[100][100] = {0};
        return helper(0,s.size()-1,dp,s);
    }
    int helper(int i, int j, int dp[][100] ,string &s){
        if(i>j) return 0;
        if(dp[i][j] > 0) return dp[i][j];
        
        int ans =1 + helper(i+1,j,dp,s);
        for(int k=i+1;k<=j;k++){
            if(s[i] == s[k])
                ans = min(ans, helper(i+1,k-1,dp,s) + helper(k,j,dp,s));
        }
        return dp[i][j] = ans;
    }
};
```
