# 1525. 字符串的好分割数目

```c++
给你一个字符串 s ，一个分割被称为 「好分割」 当它满足：将 s 分割成 2 个字符串 p 和 q ，它们连接起来等于 s 且 p 和 q 中不同字符的数目相同。

请你返回 s 中好分割的数目。

 

示例 1：

输入：s = "aacaba"
输出：2
解释：总共有 5 种分割字符串 "aacaba" 的方法，其中 2 种是好分割。
("a", "acaba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aa", "caba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aac", "aba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aaca", "ba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aacab", "a") 左边字符串和右边字符串分别包含 3 个和 1 个不同的字符。
示例 2：

输入：s = "abcd"
输出：1
解释：好分割为将字符串分割成 ("ab", "cd") 。
示例 3：

输入：s = "aaaaa"
输出：4
解释：所有分割都是好分割。
示例 4：

输入：s = "acbadbaada"
输出：2
 

提示：

s 只包含小写英文字母。
1 <= s.length <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个题比较简单，开一个长度为n的数组，记录每个位置和这个位置之前的字符出现个数，然后后从往前遍历一遍，记录相等的时刻即可。

但是有没有不使用额外空间的解法呢，当然是有的，关键点是**记录每个字符出现的总个数**（关系到以后会不会出现该字符）

代码是从讨论区随便找了一个大佬的，做了点注释

```c++
class Solution {
public:
    int numSplits(string s) {
        int ans = 0;

        vector<int> l_dic(26, 0);
        vector<int> r_dic(26, 0);
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            right += (r_dic[c] == 0);//right表示一共出现过几个不同的字符
            r_dic[c]++;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            int c = s[i] - 'a';
            left += (l_dic[c] == 0);
            l_dic[c]++;
            r_dic[c]--;
            right -= (r_dic[c] == 0);
            ans += (left == right);
        }

        return ans;
    }
};
```

---
