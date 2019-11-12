# 169. 求众数

```c++
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1 使用摩尔投票法

核心思想是两两抵消，最后剩下的一定是众数（前提是众数的个数大于 n/2）

---

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int t = nums[0];
        for(int i=1;i<nums.size();i++){
            if(t==nums[i])
                count++;
            else{
                count--;
                if(count==0){
                    t = nums[i+1];
                }
            }
        }
        return t;
    }
};
```

---

## 解法2 使用位运算

细分到每一个位（一般来讲是32位），统计所有数的每个位上的值，众数一定占主导作用（大于n/2）
最后统计出来的值还原回去就是众数。

```C++
class Solution {
public:
    int majorityElement(vector<int> &nums)
{
    int half_len = nums.size() / 2;
    int max_count = 0;

    // 统计32位中各个位1出现的次数(因为不是0就是1，
    // 知道1的次数那0出现的次数就用总数减去1出现的次数即可)
    int count[32] = {0};

    int bit_checker[32] = {1}; // bit_checker[i]的二进制第i位是1
    for (int i = 1; i < 32; i++)
    {
        bit_checker[i] = bit_checker[i - 1] << 1;
    }

    for (int item : nums)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((bit_checker[i] & item) != 0)
                {
                    count[i]++;
                }
        }
    }

    int result = 0;
    long base = 1;
    for (int i = 0; i < 32; i++)
    {
        if (count[i] > half_len)
        {
            result += base;
        }
        
        base = base << 1;
    }

    return result;
}
};

作者：varyshare
链接：https://leetcode-cn.com/problems/majority-element/solution/ji-bai-9992de-yong-hu-liang-chong-liang-yan-jie-fa/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

