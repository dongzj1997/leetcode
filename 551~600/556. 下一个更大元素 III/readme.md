# 556. 下一个更大元素 III

```c++
给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。

示例 1:

输入: 12
输出: 21
示例 2:

输入: 21
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

认真做题     x
学习一波API  √

`#include <algorithm>`

`next_permutation()`求下一个大于这个数的排列，函数的返回值是布尔类型，此外，在STL中还有`perv_permutation()`函数。

当到达最后一个最大的排列时，调用`next_permutation`的返回`false`，此时将数据变为最小排列。

---

真正做法是：

从右往左遍历 找到第一个不是顺序排列的数字,而不是第一个比最右的数小的数

找到了这个数i之后再最后的数开始往右遍历,找到第一个比i大的数j与i交换,然后再对i后面的所有数重新排序

eg: 2302431 -> 2303124

从右往左遍历先找到第一个比右边小的数字2,然后找到从右往左找到第一个比2大的数字3，交换这两个数字，然后421重新排序为124 最后得到2303124

```c++
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n < 10) return -1;
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long val = stol(str);
        if(val > INT_MAX || val <= n) return -1;
        return val;
    }
};
```

---



