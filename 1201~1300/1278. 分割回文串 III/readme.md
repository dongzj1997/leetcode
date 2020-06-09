# 1278. 分割回文串 III

```c++
给你一个由小写字母组成的字符串 s，和一个整数 k。

请你按下面的要求分割字符串：

首先，你可以将 s 中的部分字符修改为其他的小写英文字母。
接着，你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。
请返回以这种方式分割字符串所需修改的最少字符数。

示例 1：

输入：s = "abc", k = 2
输出：1
解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。
示例 2：

输入：s = "aabbc", k = 3
输出：0
解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。
示例 3：

输入：s = "leetcode", k = 8
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

很经典的一道dp，详解看注释。

```c++
class Solution {
public:
    int palindromePartition(string s, int k) {
        int len = s.size();
        if (len == k) return 0;
        vector<vector<int>> cost(len, vector<int>(len));
        // cost[i][j] 表示将从i到j的字符串变为回文需要的操作数。
        //此处可以使用dp加速，但n最大值为100 不用dp也可以
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                int l = i, r = j;
                while (l < r) {
                    cost[i][j] += s[l++] != s[r--];
                }
            }
        }
        vector<vector<int>> dp(len + 1, vector<int>(k + 1, 0x3f3f3f3f));
        //dp[i][j] 表示将前i个字符 分割为j段，最少改变字符的次数
        dp[0][0] = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= k; j++) {
                //三维dp，从0到i搜索取最小
                for (int x = 0; x < i; x++) {
                    dp[i][j] = min(dp[i][j], dp[x][j - 1] + cost[x][i - 1]);
                }
            }
        }
        return dp[len][k];
    }
};
```

---
