# 34-在排序数组中查找元素的第一个和最后一个位置

```c++
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

两次二分搜索，第一次找左边界，第二次找右边界。

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int n=nums.size(),l=0,r=n-1;
        
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>=target) r=m;
            else l=m+1;
        }
        
        if(nums[l]!=target) return res; //未找到
        
        res[0]=l;
        r=n;//第二次找的是最后一个位置+1的位置，有可能超出边
        
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<=target) l=m+1;
            else r=m;
        }
        res[1]=l-1;
        return res;
    }
};
```

---



