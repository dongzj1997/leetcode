# 525. 连续数组

```c++
给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。

 

示例 1:

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

注意: 给定的二进制数组的长度不会超过50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这题解题的关键是：
若将0当做-1，将数组的各项累加起来，

`i:j`为连续数组的充要条件是`arrSum[i]=arrSum[j]`

求出`arrSum[i]=arrSum[j]`条件下最大的`i-j`即可

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int , int> mp;
        int sum =0, len = nums.size();
        int ans = 0;
        mp[0] = -1;
        for(int i=0;i<len;i++){
            if(nums[i])
                sum++;
            else
                sum--;
            if(mp.count(sum) != 0) //如果出现过
                ans = max(ans, i - mp[sum]);
            else//该和第一次出现
                mp[sum] = i;
        }
        return ans;
    }
};
```

---



