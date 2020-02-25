# 面试题53 - II. 0～n-1中缺失的数字

```c++
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

 

示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单大

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= i;
            x ^=nums[i];
        }
        x ^= nums.size();
        
        return x;
    }
};
```

---



