# 629. K个逆序对数组

```c++
给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。

逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。

由于答案可能很大，只需要返回 答案 mod 109 + 7 的值。

示例 1:

输入: n = 3, k = 0
输出: 1
解释: 
只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。
示例 2:

输入: n = 3, k = 1
输出: 2
解释: 
数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-inverse-pairs-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

挺好的动态规划题目，最难的地方在于知道了第一层递推式以后，推第二层递推式。

n代表有几个数，k代表有几个逆序对

`f(n,k) = f(n-1,k)+f(n-1,k-1) + f(n-1,k-2) + f(n-1,k-3) + ... + f(n-1,k-n+1)`

`f(n,k+1) = f(n-1,k+1) + f(n-1,k-1) + f(n-1,k-2) + ... + f(n-1,k-n+2)`

两式相减，即得`f(n,k+1) - f(n,k) = f(n-1,k+1) - f(n-1,k-n+1)`

即`f(n,k) = f(n,k-1) + f(n-1,k) - f(n-1,k-n)`

```c++
class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = pow(10, 9)+7;
        vector<vector<long>> dp(n+1,vector<long>(k+1,0));
        for(int i = 1;i<n+1;i++){
            dp[i][0] = 1; //逆序为0的情况只有一种
        }
        
        //f(n,k) = f(n,k-1) + f(n-1,k) - f(n-1,k-n)
        for(int i = 2;i<n+1;i++){ //有几个数
            for(int j=1;j<k+1;j++){ // 有几个逆序对
                if(j-i>=0){
                    dp[i][j] = (dp[i][j-1]+dp[i-1][j]-dp[i-1][j-i])%M;
                    dp[i][j]+=M;
                }else{
                    dp[i][j] = (dp[i][j-1]+dp[i-1][j])%M;
                }
            }
        }
        return dp[n][k]%M;
    }
};
```

---



