# 1585. 检查字符串是否可以通过排序子字符串得到另一个字符串

```c++
给你两个字符串 s 和 t ，请你通过若干次以下操作将字符串 s 转化成字符串 t ：

选择 s 中一个 非空 子字符串并将它包含的字符就地 升序 排序。
比方说，对下划线所示的子字符串进行操作可以由 "14234" 得到 "12344" 。

如果可以将字符串 s 变成 t ，返回 true 。否则，返回 false 。

一个 子字符串 定义为一个字符串中连续的若干字符。

 

示例 1：

输入：s = "84532", t = "34852"
输出：true
解释：你可以按以下操作将 s 转变为 t ：
"84532" （从下标 2 到下标 3）-> "84352"
"84352" （从下标 0 到下标 2） -> "34852"
示例 2：

输入：s = "34521", t = "23415"
输出：true
解释：你可以按以下操作将 s 转变为 t ：
"34521" -> "23451"
"23451" -> "23415"
示例 3：

输入：s = "12345", t = "12435"
输出：false
示例 4：

输入：s = "1", t = "2"
输出：false
 

提示：

s.length == t.length
1 <= s.length <= 105
s 和 t 都只包含数字字符，即 '0' 到 '9' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-string-is-transformable-with-substring-sort-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

>把t按升序的团分块，比如23415分成234+15，那么首先要在s中找到包含234中所有字符的块，同时不能引入比234中任一字符还小的字符。
>
>s中的3452可以满足覆盖t中234同时不引入小于2的字符，那么多出来的字符5呢？留着下次用就行。
>
>因为之前剩下来没用到的s中字符可以累积到后面用，所以把t拆成单个字符构成的团也是一样的

```c++
class Solution {
public:
    bool isTransformable(string s, string t) {
        // s = "84532", t = "34852"
        // s中的字符，如果是大的，则只能往后移，不能往前移
        // 如果一个数很大，但是还出现在前面，说明它出生好。
        int n = s.size();
        vector<queue<int>> pos(10);
        for (int i = 0; i < n; ++i) {
            pos[s[i] - '0'].push(i);
        }
        for (int i = 0; i < n; ++i) {
            int digit = t[i] - '0';
            if (pos[digit].empty()) {
                // 字符串各个字符个数不同
                return false;
            }
            for (int j = 0; j < digit; ++j) {
                if (!pos[j].empty() && pos[j].front() < pos[digit].front()) {
                    return false;
                }
            }
            pos[digit].pop();
        }
        return true;
    }
};
```

---
