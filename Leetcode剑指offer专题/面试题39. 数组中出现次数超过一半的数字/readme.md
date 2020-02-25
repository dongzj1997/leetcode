# 面试题39. 数组中出现次数超过一半的数字

```c++
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

不同数字两两抵消，最后剩余的数字就是超过一半的数字

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int p = nums[0];
        int count = 1;
        int len = nums.size();
        
        for(int i=1;i<len;i++){
            if(nums[i] == p)
                count++;
            else{
                count--;
                if(count == 0){
                    count =1;
                    p = nums[i];
                }
                    
            }
            
        }
        return p;
    }
};
```

---



