# 994. 腐烂的橘子

```c++
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

下面给出一个错误解法，千万不要模仿，有潜在的bug，速度也不行

正确的解法还是使用bfs

```c++
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int ans = 2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)  //新鲜橘子
					grid[i][j] = INT_MAX - 1 ;

				if (grid[i][j] > 0) {
					if (i > 0 && grid[i - 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
					if (j > 0 && grid[i][j - 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
				}
			}
		}

		for (int i = n-1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (grid[i][j] > 0) {
					if (i < n - 1 && grid[i + 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
					if (j < m -1 && grid[i][j + 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
					//ans = max(ans, grid[i][j]);
					int a = 1;

				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] > 0) {
					if (i > 0 && grid[i - 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
					if (j > 0 && grid[i][j - 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
				}
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (grid[i][j] > 0) {
					if (i < n - 1 && grid[i + 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
					if (j < m - 1 && grid[i][j + 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
					//ans = max(ans, grid[i][j]);
					int a = 1;

				}
			}
		}
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] > 0) {
					if (i > 0 && grid[i - 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
					if (j > 0 && grid[i][j - 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
				}
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (grid[i][j] > 0) {
					if (i < n - 1 && grid[i + 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
					if (j < m - 1 && grid[i][j + 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
					//ans = max(ans, grid[i][j]);
					int a = 1;

				}
			}
		}
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] > 0) {
					if (i > 0 && grid[i - 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
					if (j > 0 && grid[i][j - 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
				}
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (grid[i][j] > 0) {
					if (i < n - 1 && grid[i + 1][j] != 0) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
					if (j < m - 1 && grid[i][j + 1] != 0) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
					ans = max(ans, grid[i][j]);
					int a = 1;

				}
			}
		}

		return ans == INT_MAX - 1 ? -1 : ans - 2;
	}
};
```

---



