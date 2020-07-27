# 982. 按位与为零的三元组

```c++
给定一个整数数组 A，找出索引为 (i, j, k) 的三元组，使得：

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0，其中 & 表示按位与（AND）操作符。
 

示例：

输入：[2,1,3]
输出：12
解释：我们可以选出如下 i, j, k 三元组：
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2
 

提示：

1 <= A.length <= 1000
0 <= A[i] < 2^16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triples-with-bitwise-and-equal-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

很巧妙的一个位运算写法

遍历A中的数，将该数按位取反（意思是有其他数和该值A[i] 求与一定为0）

然后不断的去掉最后一个1，出现次数记录到map之中（不断去掉最后一个1 求与也为0）

然后两个for，判断字典中有多少个符合条件的解，然后累加即可。

```c++
class Solution {
public:
    int countTriplets(vector<int>& A) {
        const int mod = (1 << 16) - 1;
        int memo[mod+1] = { 0 };

        for (int elem : A) {
            elem = elem ^ mod; //按位取反
            int i = elem;

            while (i != 0) { //将所有能于elem匹配的情况都+1
                memo[i]++;
                i = (i - 1) & elem;//所有和elem&运算的数都会和原A[i]中的数&运算得到0，相当于每一运算去掉了i中最低位的一个1.
            }

            memo[0]++;
        }

        int res = 0;
        for (auto a : A) {
            for (auto b : A) {
                res += memo[a & b];
            }
        }

        return res;
    }
};
```

---
