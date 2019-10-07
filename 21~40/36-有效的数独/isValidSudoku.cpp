#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了97.74%的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了95.45%的用户
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool a[3][9][9] = { 0 };  //分别表示行，列，网格
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

int main()
{
	Solution s = Solution();

	vector<vector<char>> input = { 
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};
           
	auto ans = s.isValidSudoku(input);
	cout << ans << endl;

	return 0;
}
