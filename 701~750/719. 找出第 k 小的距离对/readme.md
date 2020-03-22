# 719. 找出第 k 小的距离对

```c++
给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
```

---

## 解析

和之前的 “求乘法表中第k大的数”有异曲同工之妙。

将距离对作为二分的对象，先确定其下届和上界`l = 0, r = nums.back() - nums[0] + 1;`（左闭右开）

每次进行二分，取得该界的中值 **统计对于该中值m，小于m的距离对个数**

如果个数过多，说明k选取的较大，二分的时候缩小上界，`r = m;`，如果个数过少，说明k选取的较小，二分的时候扩大下界，`l = m + 1;`

注意：为什么当`cnt == k`的时候也要缩小上界呢？，此时直接返回m不行吗？

答案显然是不行的，比如第一个例子`nums = [1,3,1],k = 1`,第一次分割的时候m=1，此时正好`cnt == k`，但是我们需要的是符合条件的最小，正确答案为0，

所以`cnt == k`时m的值只能大于或者等于正确答案，所以将该上界缩小，直到l和r相等，缩小到真正的边界。

```c++
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int l = 0, r = nums.back() - nums[0] + 1;
        while(l < r){
            int m = l + (r-l)/2;
            int cnt = 0, pos = 0;
            for(int i=1;i<len;i++){
                while(nums[i] -nums[pos] > m) pos++;
                cnt += (i - pos);
            }
            if(cnt < k){
                l = m + 1;
            }else{
                r = m;
            }
            // else if(cnt > k){
            //     r = m;
            // }else{
            //     //return m;
            // }
        }
        return l;
    }
};
```

---



