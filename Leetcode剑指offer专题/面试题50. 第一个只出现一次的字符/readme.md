# 面试题50. 第一个只出现一次的字符

```c++
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    char firstUniqChar(string s) {
        int t[128] = { 0 };
        for(char c: s) t[c]++;
        for(char c: s)
            if(t[c]== 1) return c;
        return ' ';
    }
};
```

---



