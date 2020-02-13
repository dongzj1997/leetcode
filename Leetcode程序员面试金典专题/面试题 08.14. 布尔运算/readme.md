# 面试题 08.14. 布尔运算

```c++
给定一个布尔表达式和一个期望的布尔结果 result，布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成。实现一个函数，算出有几种可使该表达式得出 result 值的括号方法。

示例 1:

输入: s = "1^0|0|1", result = 0

输出: 2
解释: 两种可能的括号方法是
1^(0|(0|1))
1^((0|0)|1)
示例 2:

输入: s = "0&0&0&1^1|0", result = 1

输出: 10
提示：

运算符的数量不超过 19 个

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/boolean-evaluation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

首个通过，首个发布解题还是有点成就感的

如果你还不知道卡特兰数及其求法，可以参考xx百科，或者题目 `96. 不同的二叉搜索树中的解题`。

这个题其实也可以分算作卡特兰数的一种变形，在不同位置处分割，对两边的结果做乘积，然后累加得出最终结果。

具体细节就放在代码的注释中了，使用的是带备忘录的递归，当然改成二维数组的动态也很容易，状态转移方程的原理和递归的相同，都是分割+相乘+累加，我懒得做了，有大神写出来了可以放到评论区。

代码有点乱，对于两边不同0和1，生成最终的0，1结果部分可以定义四个变量来做看着更加简洁，不过理解了都一样。

```c++
class Solution {
public:
	//s = "1^0|0|1", result = 0
	unordered_map<string, pair<int, int > > dp;
	int countEval(string s, int result) {
		pair<int, int > ans = helper(s);
		if (result == 0)
			return ans.first;
		else
			return ans.second;
	}

	pair<int, int > helper(string s) {
		if (dp.count(s) != 0)
			return dp[s];
		int ans[2] = { 0 };
		int len = s.size();
		if (len == 1)
			if (s == "1")
				ans[1]++;
			else
				ans[0]++;
		else {
			for (int i = 1; i < len; i += 2) {
				pair<int, int > t1 = helper(s.substr(0, i));
				pair<int, int > t2 = helper(s.substr(i+1));
				switch (s[i]) {
				case '&':
					ans[0] += t1.first * t2.first + t1.second *t2.first + t2.second*t1.first;
					ans[1] += t1.second * t2.second;
					break;
				case '|':
					ans[0] += t1.first * t2.first;
					ans[1] += t1.second * t2.second + t1.first * t2.second + t2.first * t1.second;;
					break;
				case '^':
					ans[0] += t1.first * t2.first + t1.second * t2.second;
					ans[1] += t1.first * t2.second + t2.first * t1.second;
					break;
				}
			}
		}
		dp[s] = make_pair(ans[0], ans[1]);
		return { ans[0] ,ans[1] };
	}
};
```

---



