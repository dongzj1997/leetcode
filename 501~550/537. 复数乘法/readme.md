# 537. 复数乘法

```c++
给定两个表示复数的字符串。

返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:

输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2:

输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

`sscanf(a.c_str(), "%d+%di", &a1, &b1);`的写法学到了

```c++
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        
        int a1, b1, a2, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &b1);
        sscanf(b.c_str(), "%d+%di", &a2, &b2);
        
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
```

---



