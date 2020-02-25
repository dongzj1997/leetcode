# 面试题49. 丑数

```c++
我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

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



