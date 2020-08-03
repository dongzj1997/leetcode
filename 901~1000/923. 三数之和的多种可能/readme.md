# 923. 三数之和的多种可能

```c++
给定一个整数数组 A，以及一个整数 target 作为目标值，返回满足 i < j < k 且 A[i] + A[j] + A[k] == target 的元组 i, j, k 的数量。

由于结果会非常大，请返回 结果除以 10^9 + 7 的余数。

 

示例 1：

输入：A = [1,1,2,2,3,3,4,4,5,5], target = 8
输出：20
解释：
按值枚举（A[i]，A[j]，A[k]）：
(1, 2, 5) 出现 8 次；
(1, 3, 4) 出现 8 次；
(2, 2, 4) 出现 2 次；
(2, 3, 3) 出现 2 次。
示例 2：

输入：A = [1,1,2,2,2,2], target = 5
输出：12
解释：
A[i] = 1，A[j] = A[k] = 2 出现 12 次：
我们从 [1,1] 中选择一个 1，有 2 种情况，
从 [2,2,2,2] 中选出两个 2，有 6 种情况。
 

提示：

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-with-multiplicity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

模拟题意即可求解

```c++
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> mp;
        for (int n : A) {
            mp[n]++;
        }
        long ans = 0;
        int M = 1e9+7;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            int fn = (*i).first;
            int fc = (*i).second;
            auto j = i;
            for (j++; j != mp.end(); j++) {
                int sn = (*j).first;
                int sc = (*j).second;
                int need = target - fn - sn;
                if (need <= sn) break;
                ans += (long)fc * sc * mp[need];
                ans%=M;
            }
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            int fn = (*i).first;
            int fc = (*i).second;
            if (fc == 1) continue;
            int need = target - fn * 2;
            if (need == fn) {
                // 三数相等
                if (fc == 2) continue;
                ans += (long)fc * (fc - 1) * (fc - 2) / 6;
                ans%=M;
            }
            else {
                // 两数相等
                ans += (long)fc * (fc - 1) * mp[need] / 2;
                ans%=M;
            }
        }
        return ans;
    }
};
```

---
