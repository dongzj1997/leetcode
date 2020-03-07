# 540. 有序数组中的单一元素

```c++
给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

输入: [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: [3,3,7,7,10,11,11]
输出: 10
注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

二分查找，根据区间段为奇数或者偶数分开讨论，注意边界

8 ms, 在所有 C++ 提交中击败了94.88%的用户

```c++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            
            if(nums[mid] == nums[mid-1]){
                if((mid-left)%2 == 0){
                   right = mid-2;
               } else
                   left = mid+1;
            }
            else if(nums[mid] == nums[mid+1]){
                if((right-mid)%2 == 0){//若为偶数，答案在右
                   left = mid+2;
                } else //答案在左
                   right = mid-1;
            }
            else // mid指向的数和左右两边都不相等，就是答案
                return nums[mid];
        }
        return nums[left];
    }
};
```

---



