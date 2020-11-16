# 37. 解数独

```c++
编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。



一个数独。



答案被标成红色。

提示：

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int pos[9][9] = {   //矩阵每一个位置对应的九宫格位置。
		{0,0,0,1,1,1,2,2,2},
		{0,0,0,1,1,1,2,2,2},
		{0,0,0,1,1,1,2,2,2},
		{3,3,3,4,4,4,5,5,5},
		{3,3,3,4,4,4,5,5,5},
		{3,3,3,4,4,4,5,5,5},
		{6,6,6,7,7,7,8,8,8},
		{6,6,6,7,7,7,8,8,8},
		{6,6,6,7,7,7,8,8,8}
	};
	bool a[3][9][9] = { 0 };  //分别表示行，列，网格
	vector< vector<int> > ss;

	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					ss.push_back({ i,j });
				}
				else {
					int t = board[i][j] - '1';
					a[0][i][t] = 1;
					a[1][j][t] = 1;
					a[2][pos[i][j]][t] = 1;
				}
			}
		}
		Backtracking(board, 0);
	}

	bool Backtracking(vector<vector<char>>& board, int deep) {
		if (deep < ss.size()) {
			int x = ss[deep][0];
			int y = ss[deep][1];
			for (int i = 0; i < 9; i++) {
				if (a[0][x][i] || a[1][y][i] || a[2][pos[x][y]][i])
					continue;
				board[x][y] = i + '1';
				a[0][x][i] = 1;
				a[1][y][i] = 1;
				a[2][pos[x][y]][i] = 1;

				if (Backtracking(board, deep + 1)) {
					return true;
				}

				board[x][y] = '.'; //非必须
				a[0][x][i] = 0;
				a[1][y][i] = 0;
				a[2][pos[x][y]][i] = 0;
			}
			return false;
		}
		else {
			return true;
		}
	}

	/*
		bool isValidSudoku(vector<vector<char>>& board) {

			int t = 0;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.')
						continue;

					t = board[i][j] - '1';

					if (a[0][i][t] == 1)  //该行已经被占用
						return 0;
					else
						a[0][i][t] = 1;

					if (a[1][j][t] == 1)//该列已经被占用
						return 0;
					else
						a[1][j][t] = 1;


					int t2 = 3 * (i / 3) + j / 3;
					if (a[2][t2][t] == 1)//该列已经被占用
						return 0;
					else
						a[2][t2][t] = 1;
				}
			}
			return 1;
		}
	};
	*/


};
```

---
