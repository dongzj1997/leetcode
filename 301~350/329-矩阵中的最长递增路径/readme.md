# 329. 矩阵中的最长递增路径

```c++
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1，带记忆数组的dfs方法

```c++
class Solution {
public:
	vector<vector<int>> Path;
	int N=0, M=0;
	vector<vector<int>> trans = { {-1, 0} ,{1, 0},{0, 1},{0, -1} };
	

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		N = matrix.size();
		if (N == 0)
			return 0;
		M = matrix[0].size();
		int res = 1;
		Path = vector<vector<int>>(N, vector<int>(M, 0));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				res = max(res, helper(i, j, matrix));
			}
		}

		return res;
	}
	int helper(int n, int m, vector<vector<int>>& matrix) {
		if (Path[n][m] != 0)
			return Path[n][m];
		int ans = 1;
		for (auto tran : trans) {
			int new_n = n + tran[0];
			int new_m = m + tran[1];
			if (new_n >= 0 && new_n < N && new_m >= 0 && new_m < M && matrix[new_n][new_m] < matrix[n][m]) {
				ans = max(ans, 1 + helper(new_n,new_m, matrix));
			}
			
		}
		Path[n][m] = ans;
		return ans;
	}
};
```

---

## 解法2，“剥洋葱”（动态规划）

>其思路是在一个有向无环图中，会有一些不依赖于其他顶点的顶点，称为“叶子”。我们将这些叶子放在一个列表中（他们的内部排序不重要），然后将他们从图中移除。移除之后，会产生新的“叶子”。重复以上过程，就像一层一层一层地拨开洋葱的心。最后，列表中就会存储有效的拓扑排序。

>在本问题中，因为我们想要求出在整个图中最长的路径，也就是“洋葱”的层总数。因此，我们可以在“剥离”的期间计算层数，在不调用动态规划的情况下返回计数。

```java
// Topological Sort Based Solution
// An Alternative Solution
public class Solution {
    private static final int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;
    public int longestIncreasingPath(int[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        // padding the matrix with zero as boundaries
        // assuming all positive integer, otherwise use INT_MIN as boundaries
        int[][] matrix = new int[m + 2][n + 2];
        for (int i = 0; i < m; ++i)
            System.arraycopy(grid[i], 0, matrix[i + 1], 1, n);

        // calculate outdegrees
        int[][] outdegree = new int[m + 2][n + 2];
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int[] d: dir)
                    if (matrix[i][j] < matrix[i + d[0]][j + d[1]])
                        outdegree[i][j]++;

        // find leaves who have zero out degree as the initial level
        n += 2;
        m += 2;
        List<int[]> leaves = new ArrayList<>();
        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                if (outdegree[i][j] == 0) leaves.add(new int[]{i, j});

        // remove leaves level by level in topological order
        int height = 0;
        while (!leaves.isEmpty()) {
            height++;
            List<int[]> newLeaves = new ArrayList<>();
            for (int[] node : leaves) {
                for (int[] d:dir) {
                    int x = node[0] + d[0], y = node[1] + d[1];
                    if (matrix[node[0]][node[1]] > matrix[x][y])
                        if (--outdegree[x][y] == 0)
                            newLeaves.add(new int[]{x, y});
                }
            }
            leaves = newLeaves;
        }
        return height;
    }
}


```

>作者：LeetCode
>链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-leet/
>来源：力扣（LeetCode）
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
