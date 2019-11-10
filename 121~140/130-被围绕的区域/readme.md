# 130. 被围绕的区域

```c++
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) {
			return;
		}
		int rows = board.size(), cols = board[0].size();
		for (int i = 0; i < rows; i++) {  //处理左右边界
			dfs(board, i, 0);
			dfs(board, i, cols - 1);
		}
		for (int j = 1; j < cols - 1; j++) {//处理上下边界
			dfs(board, 0, j);
			dfs(board, rows - 1, j);
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == '-') {
					board[i][j] = 'O';
				}
				else {
					board[i][j] = 'X'; //只要不是边界上的O，都直接改写为X
				}
			}
		}
	}

	void dfs(vector<vector<char>>& board, int i, int j) {
		if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O') {
			board[i][j] = '-';
			dfs(board, i - 1, j);
			dfs(board, i + 1, j);
			dfs(board, i, j - 1);
			dfs(board, i, j + 1);
		}
	}
};
```

---

首先对边界上每一个'O'做深度优先搜索，将与其相连的所有'O'改为'-'。然后遍历矩阵，将矩阵中所有'O'改为'X',将矩阵中所有'-'变为'O'。
