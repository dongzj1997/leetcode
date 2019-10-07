#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了72.89%的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了98.04%的用户
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();

		//进行转置
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}

		for (auto t : matrix) {
			for (auto ttt : t) {
				cout << ttt << " , ";
			}
			cout << endl;
		}

		cout <<"-------------------------------------------" <<endl;

		for (auto &t : matrix) {
			reverse(t.begin(), t.end());
		}


		for (auto t : matrix) {
			for (auto ttt : t) {
				cout << ttt << " , ";
			}
			cout << endl;
		}

		cout << "-------------------------------------------" << endl;

	}
};
int main()
{
	Solution s = Solution();
	vector<vector<int>> input = { {1,2,3},{4,5,6},{7,8,9} };
	s.rotate(input);


	//cout << a << endl;

	return 0;
}

