# 201. 数字范围按位与

```c++
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int ans = 0,i=0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			i++;
		}
		return m <<= i;
	}
};
```

---

程序的意思是取m和n相同的最高位，因为二进制数要么从0变到1，要么从1变到0，如果不同位的话一定不相同，所以仅把最高位相同的取出来就行。
