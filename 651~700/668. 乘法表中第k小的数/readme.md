# 668. 乘法表中第k小的数

```c++
几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：

输入: m = 3, n = 3, k = 5
输出: 3
解释: 
乘法表:
1	2	3
2	4	6
3	6	9

第5小的数字是 3 (1, 2, 2, 3, 3).
例 2：

输入: m = 2, n = 3, k = 6
输出: 6
解释: 
乘法表:
1	2	3
2	4	6

第6小的数字是 6 (1, 2, 2, 3, 4, 6).
注意：

m 和 n 的范围在 [1, 30000] 之间。
k 的范围在 [1, m * n] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

通过确定上限，统计小于该上限的数字个数，根据k和数字个数的大小关系来讲这个上限进行二分（在1~n*m之间）。

如果我们需要在第i行中寻找大于num的个数，我们只要min(num / i, n)，其中（i是这一行的行号，n是矩阵的列数）num / i代表的是如果num也在第i行，它存在的列数，所以只要取最小值就是第i行不大于num的个数。

遍历m行，讲个数进行累加即可得到数字个数。。

```c++
class Solution {
public:
    int findKthNumber(int m, int n, int k){
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += min(mid / i, n);
            }
            if (k > cnt) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
```

---



