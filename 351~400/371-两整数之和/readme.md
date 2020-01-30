# 371-两整数之和

```c++
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

整体代码框架类似求最大公约数

先使用a = a ^ b;求出不进位的情况下和的值，

用int c = ((unsigned int)a & b) << 1; //存储进位  
使用(unsigned int)是防止 AddressSanitizer 对有符号左移的溢出保护处理

不断迭代，直到进位变为0

```c++
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int c = ((unsigned int)a & b) << 1; //存储进位
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
```

---

巧妙啊巧妙！
