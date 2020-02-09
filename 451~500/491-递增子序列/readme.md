# 491-递增子序列

```c++
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

写了大概一个多小时，提交的时候发现把题意理解错了，不需要自己再排序了。Orz

关键是去重，//要添加的num[i]变小，或者 本次将要第二次添加num[i]，则跳过

```c++
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        DFS(ans, path, nums, 0, -10000);

        return ans;
    }

    void DFS(vector<vector<int>>& ans, vector<int>& path, vector<int> nums, int begin, int pre_num) {

        if (path.size() >= 2) {
            ans.push_back(path);
        }

        
        unordered_set<int> s;
        for (int i = begin; i < nums.size(); ++i) {

            //要添加的num[i]变小，或者 本次将要第二次添加num[i]，则跳过
            if (nums[i] < pre_num || s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);

            path.push_back(nums[i]);
            DFS(ans, path, nums, i + 1, nums[i]);
            path.pop_back();
        }
    }
};
```

---



