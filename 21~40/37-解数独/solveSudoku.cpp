#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了94.27%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了42.41%的用户
*/

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
	vector< vector<int> > ss; //存储每一个待填空的位置。

	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					ss.push_back({ i,j });  //待填空的位置
				}
				else {
					int t = board[i][j] - '1'; //将占位符置为1
					a[0][i][t] = 1;
					a[1][j][t] = 1;
					a[2][pos[i][j]][t] = 1;
				}
			}
		}
		Backtracking(board, 0);  //从第0个待填空的位置开始递归
	}

	bool Backtracking(vector<vector<char>>& board, int deep) {
		if (deep < ss.size()) {
			int x = ss[deep][0];
			int y = ss[deep][1];
			for (int i = 0; i < 9; i++) {
				if (a[0][x][i] || a[1][y][i] || a[2][pos[x][y]][i]) // 被占位
					continue;
				board[x][y] = i + '1';
				a[0][x][i] = 1;
				a[1][y][i] = 1;
				a[2][pos[x][y]][i] = 1;

				if (Backtracking(board, deep + 1)) {
					return true;   //保证了一旦检测到可行解，之前的所有递归函数均返回。
				}

				// 执行到这里，说明上面的分支没有可行解。
				//board[x][y] = '.'; //非必须
				a[0][x][i] = 0;
				a[1][y][i] = 0;
				a[2][pos[x][y]][i] = 0;
			}
			return false; //该分支没有可行解。
		}
		else {
			return true;
		}
	}
};

int main()
{
	Solution s = Solution();

	vector<vector<char>> input = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	s.solveSudoku(input);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << input[i][j] << " , ";
		}
		cout << endl;
	}

	return 0;
}