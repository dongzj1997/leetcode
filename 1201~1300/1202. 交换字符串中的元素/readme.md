# 1202. 交换字符串中的元素

```c++
给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。

你可以 任意多次交换 在 pairs 中任意一对索引处的字符。

返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

 

示例 1:

输入：s = "dcab", pairs = [[0,3],[1,2]]
输出："bacd"
解释： 
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"
示例 2：

输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
输出："abcd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"
示例 3：

输入：s = "cba", pairs = [[0,1],[1,2]]
输出："abc"
解释：
交换 s[0] 和 s[1], s = "bca"
交换 s[1] 和 s[2], s = "bac"
交换 s[0] 和 s[1], s = "abc"
 

提示：

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用并查集，代码修修补补的太难看了，我都不忍直视

```c++
class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int len = s.size();
		vector<int> mg(len, -1);
		//for (auto& t : pairs) {
		//	int t1 = max(t[0], t[1]);
		//	int t2 = min(t[0], t[1]);
		//	t[1] = t1;
		//	t[0] = t2;
		//}
		//sort(pairs.begin(), pairs.end());
		for (auto& p : pairs) {
			int a = getfa(p[0], mg);
			int b = getfa(p[1], mg);
			if (a == p[1] || b == p[0] || a == b && a != -1) continue;
			mg[getfa(p[1], mg)] = p[0];
		}
		map<int, pair<vector<int>, vector<int> > > vc;
		for (int i = 0; i < len; i++) {
			getfa(i, mg);
			if (mg[i] == -1) {
				pair<vector<int>, vector<int> > t = { {i},{s[i]} };
				vc[i] = t;
			}
		}
		for (int i = 0; i < len; i++) {

			if (mg[i] != -1) {
				int t = getfa(i, mg);
				vc[t].first.push_back(i);
				vc[t].second.push_back(s[i]);
			}
		}

		for (auto& aa : vc) {
			auto& t = aa.second;
			sort(t.second.begin(), t.second.end());
			sort(t.first.begin(), t.first.end());
		}
		string ans = s;
		int j = 0;
		for (auto& aa : vc) {
			auto t = aa.second;
			auto &t1 = t.first;
			auto &t2 = t.second;
			for (int i = 0; i < t1.size(); i++) {
				ans[t1[i]] = t2[i];
			}

		}
		return ans;

	}

	int getfa(int a, vector<int>& mg) {
		int t = a;
		if (mg[a] == -1) return a;
		else {
			while (mg[a] != -1) {
				a = mg[a];
			}
			mg[t] = a;
		}
		return a;
	}
};
```

---

