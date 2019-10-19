class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		bool row0 = false, col0 = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					if (i == 0) row0 = true;  //由于使用首行和首列来保存整个矩阵的信息，所以首行首列是否需要置为0 就未知，需要特别保存
					if (j == 0) col0 = true;
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;
			}
		}
		if (col0)
			for (int i = 0; i < m; i++) matrix[i][0] = 0;
		if (row0)
			for (int j = 0; j < n; j++) matrix[0][j] = 0;
	}
};