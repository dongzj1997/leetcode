# 477-汉明距离总和

```c++
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

时间复杂度：O(32*n)

```c++
class Solution {
public:

    int totalHammingDistance(vector<int>& nums) {
        int ans =0;
        int len = nums.size();
        for(int i=0;i<32;i++){
            int count =0;
            for(int n:nums){
                count += (n >> i) & 1;
            }
            ans += count * (len - count);
        }
        return ans;
    }
};
```

---



