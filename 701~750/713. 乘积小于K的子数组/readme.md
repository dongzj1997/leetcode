713. 乘积小于K的子数组

```c++
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:

0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6
```

---

简单题，`sum += (r-l + 1);`表示的是以r结尾的序列个数，之后执行r++，又会有新的一批序列出现。

```c++
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2) return 0;
        int l = 0,sum = 0,acc = 1;
        for(int r = 0; r<nums.size(); r++){
            acc *= nums[r];
            while(acc >= k){
                acc /= nums[l];
                l++;
            }
            sum += (r-l + 1);
        }
        return sum;
    }
};
```

---



