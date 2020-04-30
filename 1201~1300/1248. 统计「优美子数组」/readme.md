# 1248. 统计「优美子数组」

```c++
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

 

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

首先容易想到的是字典，// arr[i] 表示奇数个数为i的起始位置个数
每次利用两数之和的方法快速找到需要的个数就能给出结果。

此外，还有双指针的方法，时间复杂度也是o（n），并且不需要额外使用内存。

```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> arr;
        int n = nums.size(), res = 0, cur = 0;
        arr[0] = 1;
        for (int i = 0; i < n; ++i) {
            cur += nums[i] % 2;  //从开头到当前有多少个 数字为奇数
            if (cur - k >= 0) {
                res += arr[cur - k]; // arr[i] 表示奇数个数为i的起始位置个数
            }
            ++arr[cur];
        }
        return res;
    }
};

```

---



