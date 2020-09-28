# 1589. 所有排列中的最大和

```c++
有一个整数数组 nums ，和一个查询数组 requests ，其中 requests[i] = [starti, endi] 。第 i 个查询求 nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi] 的结果 ，starti 和 endi 数组索引都是 从 0 开始 的。

你可以任意排列 nums 中的数字，请你返回所有查询结果之和的最大值。

由于答案可能会很大，请你将它对 109 + 7 取余 后返回。

 

示例 1：

输入：nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
输出：19
解释：一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
总和为：8 + 3 = 11。
一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。
示例 2：

输入：nums = [1,2,3,4,5,6], requests = [[0,1]]
输出：11
解释：一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。
示例 3：

输入：nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
输出：47
解释：一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。
 

提示：

n == nums.length
1 <= n <= 105
0 <= nums[i] <= 105
1 <= requests.length <= 105
requests[i].length == 2
0 <= starti <= endi < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-obtained-of-any-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

周赛的时候用遍历`1 <= n <= 10^5`的方法过了，用了两个数组，第一个表示当前位置为区间开始位置的个数，第二个表示当前n为区间终止位置的个数。

更为合适的做是用一个**差分数组**

如果是区间开始位置，将差分数组的对应位置+1，如果是区间结束的位置，将差分数组的结束位置后移一位，再-1.

最后对差分数组求一个前缀和，就是包含当前位置的区间个数。

排序即可。

```c++
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int M = 1e9+7;
        int len = nums.size();
        vector<int> dif(len); // 差分数组
        for(auto& request:requests){
            dif[request[0]]++;
            if(request[1]+1<len)
                dif[request[1]+1]--;
        }
        for(int i=1;i<len;i++)
            dif[i]+=dif[i-1];
        sort(nums.begin(),nums.end());
        sort(dif.begin(),dif.end());
        long long ans=0;
        for(int i = 0; i < len; i++)
            ans = (ans + (long long)dif[i]*nums[i]) % M;
        return ans;
    }
};
```

---
