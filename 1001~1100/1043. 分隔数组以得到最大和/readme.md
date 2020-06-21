# 1043. 分隔数组以得到最大和

```c++
给出整数数组 A，将该数组分隔为长度最多为 K 的几个（连续）子数组。分隔完成后，每个子数组的中的值都会变为该子数组中的最大值。

返回给定数组完成分隔后的最大和。

 

示例：

输入：A = [1,15,7,9,2,5,10], K = 3
输出：84
解释：A 变为 [15,15,15,9,10,10,10]
 

提示：

1 <= K <= A.length <= 500
0 <= A[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-for-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这种一维的dp题最主要的是要盯住边界（虽然二维的也要盯住边界）

其实就是确定是开区间还是闭区间，不要随便混用 （个人喜欢都是使用闭区间）

j将数组分为了两部分，第一部分是 从 `0` 到  `i - j` （左闭右闭），他们的值是`dp[i-j]`

此时要注意讨论边界 `（i-j）< 0`,也就是 `i < j`, 如果小于0，则说明第一部分不存在，让其值为0即可。

第二部分是从  `i - j + 1` 到 `i`，（左闭右闭），这一段的长度为 `j`

假设这一段区间的最大值为mx，则这一段的值为`j * mx`。

改变j的过程中两端相加取最大就是结果。

```c++
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
        vector<int> dp(len,0);
        for(int i=0;i<len;i++){
            int mx =0;
            for(int j =1; j <= K && i - j + 1 >= 0; j++){ //i - j + 1 是最左端（包含）
                mx = max(mx,  A[i - j + 1]);
                int t = (i < j) ? 0 : dp[i - j];
                dp[i] = max(dp[i], t + j * mx);
            }
        }
        return dp[len-1];
    }
};
```

---
