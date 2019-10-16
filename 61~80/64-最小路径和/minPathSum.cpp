#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


/*
执行用时 :8 ms, 在所有 cpp 提交中击败了94.89%的用户
内存消耗 :10.3 MB, 在所有 cpp 提交中击败了99.31%的用户
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		if (n == 0)
			return 0;
		int m = grid[0].size();
		if (m == 0)
			return 0;
		for (int i = 1; i < m; i++)
		{
			grid[0][i] += grid[0][i - 1];

		}
		for (int i = 1; i < n; i++)
		{
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[n - 1][m - 1];
	}
};


int main()
{

	int aa = INT_MAX;
	int bb = 5;

	long long  c = (long long)aa + (long long)bb;


	Solution s = Solution();
	vector<vector<int>> input = { {0},{0},{1},{0} };
	auto a = s.minPathSum(input);

	/*for (auto line : a) {
		for (auto c : line) {
			cout << c << " , ";
		}
		cout << endl;
	}*/

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	cout << a << endl;

	return 0;
}