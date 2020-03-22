# 704. 二分查找

```c++
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

两种写法，看清楚lo和hi围成的区间是否为左闭右开，还是都是`闭区间`

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(lo < hi){
            int mi = lo + (hi - lo )/2;
            if(nums[mi] == target) return mi;
            if(nums[mi] > target){
                hi = mi;
            }else{
                lo = mi + 1;
            }
        }
        return -1;
    }
};
```

---

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mi = lo + (hi - lo )/2;
            if(nums[mi] == target) return mi;
            if(nums[mi] > target){
                hi = mi - 1;
            }else{
                lo = mi + 1;
            }
        }
        return -1;
    }
};
```


