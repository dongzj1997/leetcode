# 795. 区间子数组个数

```c++
给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。

求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。

例如 :
输入: 
A = [2, 1, 4, 3]
L = 2
R = 3
输出: 3
解释: 满足条件的子数组: [2], [2, 1], [3].
注意:

L, R  和 A[i] 都是整数，范围在 [0, 10^9]。
数组 A 的长度范围在[1, 50000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

评论区大神的解法：最大元素满足大于等于L小于等于R的子数组个数 = 最大元素小于等于R的子数组个数 - 最大元素小于L的子数组个数

```c++
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // 最大元素满足大于等于L小于等于R的子数组个数 = 最大元素小于等于R的子数组个数 - 最大元素小于L的子数组个数
        return helper(A,R) - helper(A,L-1);
    }
    int helper(vector<int>& A, int Max) {
        int res = 0;
        int numSubarry = 0;
        for (int num : A) {
            if (num <= Max) {
                numSubarry++;
                res += numSubarry;
            } else {
                numSubarry = 0;
            }
        }
        return res;
    }
};
```

---



