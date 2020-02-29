# 面试题44. 数字序列中某一位的数字

```c++
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
 

限制：

0 <= n < 2^31
注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
1 2 3 4 5 6 7 8 9 10 11 12 13 14
                             18 19
                              9 10
```


```c++
class Solution {
public:
	int findNthDigit(long n) {
		int i = 1;
		while (1)
		{
			long t = i * (pow(10, i - 1)) * 9;
			if (n > t) {
				n -= t;  //小于区间的值要减去，知道得到确定的区间
				i++;
			}
			else {
                
                
                
				int num = (n - 1) / i + pow(10, i - 1);  //num为选中的整数， = 偏移 + 基数
                n = (n - 1)%i;
				string a = to_string(num);
				//int offset = n % i == 0 ? i - 1 : n % i - 1;
				return a[n] - '0';
			}
                  
		}	
	}
};
```

---



