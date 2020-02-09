# 442. 数组中重复的数据

```c++
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

可以在输入数组中用数字的正负来表示该位置所对应数字是否已经出现过。遍历输入数组，给对应位置的数字取相反数，如果已经是负数，说明前面已经出现过，直接放入输出数组。

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if (nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            } else {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
```

---



