#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :28 ms, 在所有 cpp 提交中击败了92.41%的用户
内存消耗 :11.3 MB, 在所有 cpp 提交中击败了74.58%的用户
*/

//这道题的关键是使用vector<vector<bool>> available;来存储已经用过的变量防止元素重复使用
class Solution {
public:
	int len,m,n;
	vector<vector<bool>> available;
	bool exist(vector<vector<char>>& board, string word) {

		len = word.size();
		m = board.size();
		n = board[0].size();
		if (len == 0)
			return true;

		available = vector<vector<bool>>(m, vector<bool>(n, true));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					if (dfs(1,i,j,board,word))
						return true;
				}
			}
		}
		return false;

	}

	bool dfs(int deep,int i,int j, vector<vector<char>>& board, string& word) {
		if (deep == len)
			return true;
		char c = word[deep];
		available[i][j] = false;
		if (i - 1 >= 0 && available[i-1][j] &&board[i - 1][j] == c) {    //上
			if (dfs(deep + 1, i - 1, j, board, word))
				return true;
		}
		if (i + 1 < m && available[i + 1][j] && board[i + 1][j] == c) {    //下
			if (dfs(deep + 1, i + 1, j, board, word))
				return true;
		}
		if (j - 1 >= 0 && available[i][j - 1] && board[i][j-1] == c) {    //左
			if (dfs(deep + 1, i , j-1, board, word))
				return true;
		}
		if (j + 1 < n && available[i][j + 1] && board[i][j+1] == c) {    //右
			
			if (dfs(deep + 1, i , j+1, board, word))
				return true;
		}
		available[i][j] = true;
		return false;
	}
};
int main()
{
	Solution s = Solution();
	vector<vector<char>> input = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	auto a = s.exist(input, "ABCCED");

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}
	cout << a << endl;

	return 0;
}

