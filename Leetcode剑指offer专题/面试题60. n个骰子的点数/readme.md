# 面试题60. n个骰子的点数

```c++
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

概率累积，简单

第一遍写的时候没注意要新建一个vector进行累计，直接使用`ans[j + k] += ans[j] * s;`发现不行

写完看评论发现大多数人方法逆着使用dp，完了扩充一下，写篇思路详解

```c++
class Solution {
public:
	vector<double> twoSum(int n) {
		int len = 5 * n;
		double s = 1.0 / 6.0;
		vector<double> ans(6, s);

		for (int i = 1; i < n; i++) {
			int right = 5 * i;
			vector<double> t(right + 6, 0);
			for (int j = 0; j <= right; j++) {
				for (int k = 0; k < 6; k++) {
					t[j + k] += ans[j] * s;
				}
			}
			ans = t;
		}
		return ans;
	}
};

```

---



