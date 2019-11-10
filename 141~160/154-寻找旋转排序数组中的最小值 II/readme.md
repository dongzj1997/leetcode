# 154-寻找旋转排序数组中的最小值 II

```c++
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0
说明：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[right]>nums[mid])
                right=mid;
            else if(nums[right]<nums[mid])
                left=mid+1;
            else
                right--;
        }
        return nums[left];
    }
};
```

---

有重复节点最大的问题是：例如 [1, 0, 1, 1, 1] 和 [1, 1, 1, 0, 1]，在 left = 0, right = 4, mid = 2 时，无法判断 mid 在哪个排序数组中。

采用 right = right - 1 解决此问题。
