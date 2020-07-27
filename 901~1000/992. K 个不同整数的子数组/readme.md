# 992. K 个不同整数的子数组

```c++
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

 

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个题算是滑动窗口的一个变形吧。

传统的双指针滑动窗口，两个指针l和r都是往前走不后退的，这就保证了最坏情况下时间复杂度是O（n）

但是本题的情况特殊，左边界移动以后任然可以构成解，所以采取的策略是固定有边界（有边界不后退）

然后对每一个固定的右边界，尝试向右滑动左边界，求出以该右边界为边界的所有解

最后将左边界滑动回来，尝试新的右边界。

```c++
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int len = A.size();
        int* mp = (int*)malloc((len + 1) * sizeof(int));
        memset(mp, 0, (len + 1) * sizeof(int));
        int cnt = 0;
        int ans = 0;
        int l = 0, r = 0;
        while (r < len) {
            mp[A[r]]++;
            if (mp[A[r]] == 1)
                cnt++;
            r++;
            while (cnt > K) { //尝试缩小窗口
                mp[A[l]]--;
                if (mp[A[l]] == 0) {
                    cnt--;
                }
                l++;
            }
            int t = l;
            while (cnt == K) {
                ans++;
                mp[A[t]]--;
                if (mp[A[t]] == 0) {
                    cnt--;
                }
                t++;
            }
            //恢复
            t--;
            while (t >= l) {
                mp[A[t]]++;
                if (mp[A[t]] == 1)
                    cnt++;
                t--;
            }
        }
        return ans;
    }
};

```

---
