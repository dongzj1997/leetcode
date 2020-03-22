# 718. 最长重复子数组

```c++
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
```

---

简单

```c++
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int len1 = A.size(), len2 = B.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        int ans = 0;
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
```

---



