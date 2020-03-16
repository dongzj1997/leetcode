# 673. 最长递增子序列的个数


```c++
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

相比于普通的最长子序列，与之不同是还要额外记录每个节点的最长子序列对应的组合数量，新的组合数量由之前的累计而来。

```c++
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp(len, 1);
        vector<int> ans(len, 1);
        
        int m = 1, res = 1;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i] >nums[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        ans[i] = ans[j];
                    }else if(dp[i] == dp[j] + 1)
                        ans[i] += ans[j];
                }
            }
            if(m < dp[i]){
                m = dp[i];
                res = ans[i];
            }else if(m == dp[i])
                res += ans[i];

        }
        
        return res;
        
    }
};
```

---



