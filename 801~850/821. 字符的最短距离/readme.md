# 821. 字符的最短距离

```c++
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:

输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:

字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先从左到右扫描一遍，然后从右到左再扫描一遍，取两次扫描的较小值即可。

```c++
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        const int n = S.size();
        vector<int> dp(n, 0x3f3f3f3f);

        int pre = -1; 
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                dp[i] = 0;
                pre = i;
            }
            else if (pre >= 0) {
                dp[i] = min(dp[i], i - pre);
            }
        }
        pre = n; 
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) {
                pre = i;
            }
            else if (pre < n) {
                dp[i] = min(dp[i], pre - i);
            }
        }
        return dp;
    }
};

```

---



