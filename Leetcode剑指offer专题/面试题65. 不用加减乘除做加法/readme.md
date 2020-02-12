# 面试题65. 不用加减乘除做加法

```c++
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

 

示例:

输入: a = 1, b = 1
输出: 2
 

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用`(unsigned int)`来避免`int`溢出的错误提示

在c++ 中使用`static_cast`或显得更加C++

```c++
class Solution {
public:
	int add(int a, int b) {
		unsigned int carry = 0;
		do {
			carry = ((unsigned int)a & (unsigned int)b) <<1;
			a = a ^ b;
			b = carry;
		} while (carry != 0);

		return a;
	}
};
```

---



