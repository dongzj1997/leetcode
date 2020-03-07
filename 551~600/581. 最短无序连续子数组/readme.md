# 581. 最短无序连续子数组

```c++
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

从左到右，记录最大值为t，遇到的`nums[i] < t` 表示i需要交换，不断更新i，最大的i就是要排序区间的**右边界**。，
同理，从右到左，求出左边界。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0,r = 0,len = nums.size();
        if(len < 2) return 0;
        int t = nums[0];
        for(int i=1;i<len;i++){
            if(nums[i] < t){
                l = i;
            }else{
                t = nums[i];
            }
        }
        
        t = nums[len -1];
        for(int i=len -2;i>=0;i--){
            if(nums[i] > t){
                r = i;
            }else{
                t = nums[i];
            }
        }
        return l-r + ((l-r)!=0);
    }
};
```

---



