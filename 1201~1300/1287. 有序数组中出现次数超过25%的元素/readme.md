# 1287. 有序数组中出现次数超过25%的元素

```c++
给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

 

示例：

输入：arr = [1,2,2,6,6,6,6,7,10]
输出：6
 

提示：

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

！ 来源于leetcode官方解题。

这道题虽然是easy，但是如果深究的话一点也不easy。

题目给我们的是非递减的 有序 整数数组，所以可以尝试使用二分查找。

根据题目要求，满足条件的整数 `x` 至少在数组 `arr` 中出现了 `span = arr.length / 4 + 1` 次，那么我们可以断定：数组 `arr` 中的元素 `arr[0]`, `arr[span]`, `arr[span * 2]`, ... 一定包含 `x`。

我们可以使用反证法证明上述的结论。假设 `arr[0], arr[span], arr[span * 2]`, ... 均不为 `x`，由于数组 `arr` 已经有序，那么 `x` 只会连续地出现在 `arr[0], arr[span], arr[span * 2]`, ... 中某两个相邻元素的间隔中，因此其出现的次数最多为` span - 1 `次，这与它至少出现 `span` 次相矛盾。

有了上述的结论，我们就可以依次枚举 `arr[0], arr[span], arr[span * 2]`, ... 中的元素，并将每个元素在数组 `arr` 上进行二分查找，得到其在 `arr` 中出现的位置区间。如果该区间的长度至少为 `span`，那么我们就得到了答案。

另外，在c++17中，可以使用 `auto [iter_l, iter_r] = equal_range(arr.begin(), arr.end(), arr[i])`来替代`lower_bound`和 `upper_bound`。

```c++
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span) {
            auto l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (r - l >= span) {
                return arr[i];
            }
        }
        return -1;
    }
};

```

---



