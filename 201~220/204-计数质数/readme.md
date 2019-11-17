# 204. 计数质数

```c++
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

---

```c++
class Solution {
public:
	int countPrimes(int n) { //筛法求素数
		if (n <= 2)
			return 0;
		vector<bool> a(n , false);
		int count=0; //因为把2算上了
		int i = 2;
		while (i < n) {
			if (a[i] == false) {
				count++;
				for (int t = 2; t * i < n; t++) {
					a[t * i] = true;
				}
			}
			i++;
		}
		return count;
	}
};
```

---

## 筛法求素数

