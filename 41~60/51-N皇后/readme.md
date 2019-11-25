# 51. N皇后

```c++
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<vector<string> > res;
	bool valid(int n, vector<int>& cols) {
		if (cols.size() <= 1)
			return true;
		int row = cols.size() - 1;
		int col = cols.back();
		for (int r = 0; r < row; ++r) {
			int c = cols[r];
			if (c == col || abs(c - col) == abs(r - row))
				return false;
		}
		return true;
	}
	void backtrace(int n, vector<int>& cols) {
		if (!valid(n, cols)) 
			return;
		if (cols.size() == n) {  //找到合适的解
			vector<string> s;
			for (auto& c : cols) {
				string t(n, '.');
				t[c] = 'Q';
				s.push_back(t);
			}
			res.push_back(s);
			return;
		}
		for (int i = 0; i < n; i++) {
			cols.push_back(i);
			backtrace(n, cols);
			cols.pop_back();
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<int> cols; 
		backtrace(n, cols);
		return res;
	}
};
```

---

老生常谈
