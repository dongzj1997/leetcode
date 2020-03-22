# 698. 划分为k个相等的子集

```c++
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 

注意:

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

暴力搜索，大概能击败10%

加入了随机搜索策略，结果还不如不加。

```c++
class Solution {
public:
    int k;
    int tgt;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums) sum += n;
        tgt = sum / k;
        if (sum % k != 0) return false;
        sort(nums.begin(), nums.end());
        if (nums.back() > tgt) return false;
        this->k = k;
        vector<int> bkt(k, 0);
        return helper(bkt, 0, nums);
    }

    bool helper(vector<int>& bkt, int p, vector<int>& nums) {
        if (p == nums.size()) return true;
        int n = nums[p];
        int next_n = p == (nums.size() - 1) ? 0 : nums[p + 1];

        int offset = rand()% k;
        for (int i = 0; i < k; i++) {
            int offset_i = (i + offset) % k;
            int rest = tgt - bkt[offset_i];
            if (rest == n || rest - n - next_n >= 0) {
                bkt[offset_i] += n;
                if (helper(bkt, p + 1, nums)) return true;
                bkt[offset_i] -= n;
            }
        }
        return false;
    }
};
```

---



