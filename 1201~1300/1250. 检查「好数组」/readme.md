# 1250. 检查「好数组」

```c++
给你一个正整数数组 nums，你需要从中任选一些子集，然后将子集中每一个数乘以一个 任意整数，并求出他们的和。

假如该和结果为 1，那么原数组就是一个「好数组」，则返回 True；否则请返回 False。

 

示例 1：

输入：nums = [12,5,7,23]
输出：true
解释：挑选数字 5 和 7。
5*3 + 7*(-2) = 1
示例 2：

输入：nums = [29,6,10]
输出：true
解释：挑选数字 29, 6 和 10。
29*1 + 6*(-3) + 10*(-1) = 1
示例 3：

输入：nums = [3,6]
输出：false
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-good-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

>求最大公约数是否为1.  
>裴蜀定理:  
>若a,b是整数,且gcd(a,b)=d，那么对于任意的整数x,y,ax+by都一定是d的倍数，
>特别地，一定存在整数x,y，使ax+by=d成立。
> a,b互质的充要条件是存在整数x,y使ax+by=1.


```c++
class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    bool isGoodArray(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0];
        for(int i=1;i<len;i++){
            ans = gcd(ans, nums[i]);
            if(ans == 1) return true;
        }
        return ans == 1;
    }
};
```

---



