# 365. 水壶问题

```c++
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/water-and-jug-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先用辗转相除法求a，b的最大公约数，然后看这个公约数能否被z整除

其实是求解 `ax + by = z`，如果桶为`A,B`，那么一定能够获得`A，A-B，B-（A-B）=2B-A，A-（2B-A）=2A-2B，A-（B-A）=2A-B`，最终的值都包含A与B，因为X、Y也可以等于0。 因此只要找到A与B的最大公约数即可。

```c++

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		int a = max(x, y);
		int b = min(x, y);
        if (z == 0)
			return true;
        if (b == 0)
			return a == z;

		if (z > a+b) {
			return false;
		}

		while (a % b != 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		printf("commdiv: %d ", b);
		return z % b == 0;
	}
};
```

---



