# 954. 二倍数对数组

```c++
给定一个长度为偶数的整数数组 A，只有对 A 进行重组后可以满足 “对于每个 0 <= i < len(A) / 2，都有 A[2 * i + 1] = 2 * A[2 * i]” 时，返回 true；否则，返回 false。

 

示例 1：

输入：[3,1,3,6]
输出：false
示例 2：

输入：[2,1,2,6]
输出：false
示例 3：

输入：[4,-2,2,-4]
输出：true
解释：我们可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
示例 4：

输入：[1,2,4,16,8,4]
输出：false
 

提示：

0 <= A.length <= 30000
A.length 为偶数
-100000 <= A[i] <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-of-doubled-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

字典的基本用法

利用字典map的特性，从小到大依次检查，再排除

注意如果是负数，则转为正数，用另一个字典记录。

```c++
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> m1;
        map<int, int> m2;
        for (auto& num : A) {
            if (num < 0) m2[-num]++;
            else m1[num]++;
        }
        for (pair<int, int> p1 : m1) {
            if (p1.first == 0) {
                if (p1.second & 1 == 1) return false;
                else continue;
            }
            if (p1.second == 0) continue;
            int t = p1.first * 2;
            if (m1.count(t) != 0 && m1[t] >= p1.second) {
                m1[t] -= p1.second;
            }
            else {
                return false;
            }
        }
        for (pair<int, int> p1 : m2) {
            if (p1.first == 0) {
                if (p1.second & 1 == 1) return false;
                else continue;
            }
            if (p1.second == 0) continue;
            int t = p1.first * 2;
            if (m2.count(t) != 0 && m2[t] >= p1.second) {
                m2[t] -= p1.second;
            }
            else {
                return false;
            }

        }
        return true;
    }
};
```

---
