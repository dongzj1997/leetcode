# 面试题51. 数组中的逆序对

```c++
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

通过次数1,156提交次数2,527

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

思路参考了[@liweiwei1419](https://leetcode-cn.com/u/liweiwei1419/)的解题.

在归并排序归并的时候，统计出某个元素与之前或者之后元素的逆序的个数。

```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        }
        vector<int> temp(len, 0);
        return helper(nums, 0, len - 1, temp);
    }
    
    int helper(vector<int>& nums, int left, int right, vector<int>& temp){
        if (left == right) return 0;
        int mid = (left + right) /2;
        
        int innerpart = helper(nums, left, mid, temp) + helper(nums, mid + 1, right, temp);//组内的逆序对
        
        if (nums[mid] <= nums[mid + 1]) {
            return innerpart;
        }
        
        int betw_part = 0;
        
        for (int i = left; i <= right; i++) {
            temp[i] = nums[i];
        }

        int i = left;
        int j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i > mid) {
                //左边检索完
                nums[k] = temp[j];
                j++;
            } else if (j > right) {
                //右边检索完
                nums[k] = temp[i];
                i++;
            } else if (temp[i] <= temp[j]) {
                //非逆序对
                nums[k] = temp[i];
                i++;
            } else {
                // 出现逆序对
                nums[k] = temp[j];
                j++;
                betw_part += (mid - i + 1);
            }
        }

        
        return innerpart + betw_part;


    }
    
};
```

---



