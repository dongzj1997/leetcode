# 354. 俄罗斯套娃信封问题

```c++
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:

	// 按宽度升序排列，如果宽度一样，则按高度降序排列
	//( 对于宽度 w 相同的数对，要对其高度 h 进行降序排序。因为两个宽度相同的信封不能相互包含的，逆序排序保证在 w 相同的数对中最多只选取一个。)
	static bool cmp(const vector<int> p1, const vector<int> p2) {
		if (p1[0] == p2[0]) {
			return p1[1] > p2[1];
		}
		else {
			return p1[0] < p2[0];
		}
	}
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		if (envelopes.size() == 0) 
			return 0;
		sort(envelopes.begin(), envelopes.end(), cmp);
		vector<int> dp(envelopes.size(), 1);
		int mx = 1;
		for (int i = 1; i < envelopes.size(); i++) {
			for (int j = i - 1; j >= 0; j--)
				if (envelopes[j][1] < envelopes[i][1] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					mx = max(dp[i], mx);
				}
		}

		return mx;
	}
	
};
```

---

先将长度由小到大排列，相同长度的宽度由大到小排列，问题就转化为一个最长上升子序列的问题，用两种方法都可以解决

