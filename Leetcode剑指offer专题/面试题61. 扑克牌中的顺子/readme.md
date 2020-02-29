# 面试题61. 扑克牌中的顺子

```c++
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

 

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mun_zero = 0;
        for(int n : nums){
            if( n == 0)
                mun_zero ++;
            else
                break;
        }
        
        for(int i=mun_zero + 1;i<5;i++){
            if(nums[i] - nums[i-1] != 1){
                if(nums[i] == nums[i-1])
                    return false;
                if(nums[i] - nums[i-1] - 1 <= mun_zero){
                    mun_zero -= nums[i] - nums[i-1] - 1;
                }
                else
                    return false;
            }
        }
        return true;
    }
};


```

---

### 另一种更简单的方法

1. 统计0的个数

2. 看有没有重复

3. 看最大最小值的差有没有超过四+0的个数

不过我觉得差不多
