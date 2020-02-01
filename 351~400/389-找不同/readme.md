# 389. 找不同

```c++
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

异或位运算

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        int result=0;
        for(char c:s)
            result^=(c-'a');
        for(char c:t)
            result^=(c-'a');
        return char('a'+result);
    }
};
```

---



