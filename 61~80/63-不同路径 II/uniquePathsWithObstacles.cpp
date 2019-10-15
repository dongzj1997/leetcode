#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


/*
执行用时 :4 ms, 在所有 cpp 提交中击败了90.96%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了97.84%的用户
*/


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();  //n行
		int m = obstacleGrid[0].size(); //m列

		if (obstacleGrid[0][0] == 1) {
			return 0;
		}
		obstacleGrid[0][0] = 1;
		for (int j = 1; j < m; j++) {

			obstacleGrid[0][j] = !obstacleGrid[0][j] && obstacleGrid[0][j-1];
		}

		for (int i = 1; i < n; i++) {
			obstacleGrid[i][0] = !obstacleGrid[i][0] && obstacleGrid[i-1][0];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (obstacleGrid[i][j]) {
					obstacleGrid[i][j] = 0;
				}
				else {
					long long t = (long long)obstacleGrid[i - 1][j] + (long long)obstacleGrid[i][j - 1];
					//obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
					if (t > INT_MAX) {
						obstacleGrid[i][j] = 0;
					} //宁可这种操作也不重开数组
					else {
						obstacleGrid[i][j] = (int)t;
					}
				}
			}
		}

		return obstacleGrid[n - 1][m - 1];
	}
};

int main()
{

	int aa = INT_MAX;
	int bb = 5;

	long long  c = (long long)aa + (long long)bb;


	Solution s = Solution();
	vector<vector<int>> input = { {0},{0},{1},{0} };
	auto a = s.uniquePathsWithObstacles(input);

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