# 面试题10- II. 青蛙跳台阶问题

```c++
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
提示：

0 <= n <= 100
注意：本题与主站 509 题相同：https://leetcode-cn.com/problems/fibonacci-number/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个和兔子生孩子一样都是斐波那契，只是将上一题的a，b初始值变一下就可以。

```c++
class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1)
			return 1;

		int a = 1, b = 1;
		for (int i = 1; i < n; i++) {
			a = a + b;
			b = a - b;
			a %= 1000000007;
		}
		return a;
    }
};
```

---



