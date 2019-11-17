# 231. 2的幂

```c++
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

统计32位数中 某一位为1 的个数，如果是二的幂则个数为1

![img](./1.bmp)

```c++
class Solution {
public:
	bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
		const int bit = 32;
		int a = 1;
		int count = n & a;
		for (int i=1; i < bit; i++) {
            a <<= 1;
			if ( (n & a) != 0) { //说明此位为1
				count++;
				if (count > 1)
					return false;
			}
			
		}
		return count == 1;
	}
};
```

---

## 另一种解法

return (n > 0) && (n & -n) == n;

或者：

```c++
if(n<=0)
    return false;
if((n&n-1)==0)
    return true;
return false;
```
