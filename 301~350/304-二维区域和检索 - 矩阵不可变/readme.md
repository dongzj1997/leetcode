# 304. 二维区域和检索 - 矩阵不可变

```c++
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。


上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class NumMatrix {
public:
	vector<vector<long>> V;
	NumMatrix(vector<vector<int>>& matrix) {
		long sum = 0;
        
		int m = matrix.size();
        if (m == 0)
			return;
		int n = matrix[0].size();

		V = vector<vector<long>>(m+1, vector<long>(n+1,0));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				V[i][j] = matrix[i - 1][j - 1] + V[i][j - 1] + V[i - 1][j] - V[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2){
		
		return V[row2+1][col2+1] - V[row2 + 1][col1] - V[row1][col2 + 1] + V[row1][col1];
	}
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```

---

和上一道题一样，唯一区别是使用二维的动态规划（其实第一题也是不过太简单）

总体来说没难度，属于那种看完题就知道怎么做的那种。
