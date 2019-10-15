class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int l = 0, r = n - 1, t = 0, b = n - 1;  // 上下左右
		vector<vector<int>> ans(n, vector<int>(n, 0));

		int num = 1, max = n * n;
		while (num <= max) {
			for (int i = l; i <= r; i++) ans[t][i] = num++; // left to right.
			t++;
			for (int i = t; i <= b; i++) ans[i][r] = num++; // top to bottom.
			r--;
			for (int i = r; i >= l; i--) ans[b][i] = num++; // right to left.
			b--;
			for (int i = b; i >= t; i--) ans[i][l] = num++; // bottom to top.
			l++;
		}
		return ans;
	}
};
