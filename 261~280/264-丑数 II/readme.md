# 264. 丑数 II

```c++
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

使用三个指针index1，2，3来记录2，3，5分别乘什么（因为2，3，5乘以丑数也必然是丑数）

求下一个丑数时，取指针对应权重所得积最小的那个。然后移动指针应该指向下一个丑数。（idx[]中保存的是丑数数组下标）

要使用三个并列的if让指针指向一个更大的数，不能用if-else。例如：丑数6，可能由于丑数2乘以权重3产生；也可能由于丑数3乘以权重2产生。等等。

```c++
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ugly(n, 1);
		int next;
		int index1 = 0, index2 = 0, index3 = 0; //因为ugly是1，所以要从0开始
		for (int i = 1; i < n; i++) {
			next = min(2 * ugly[index1], min(3 * ugly[index2], 5 * ugly[index3]));
			if (2 * ugly[index1] == next) // 不要用if-else，可能出现一个next即对应2，又对应3 的情况
				index1++;
			if (3 * ugly[index2] == next) //
				index2++;
			if (5 * ugly[index3] == next)
				index3++;
			ugly[i] = next;
		}
		return ugly[n-1];
	}
};
```

---

除此之外，还可以使用最小堆，时间复杂度为O（n*logn）
