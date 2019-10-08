#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了52.96%的用户
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int top = 0, left = 0;  //上，左边界
		int bottom = matrix.size(); //下边界
		if (bottom == 0) {
			return {};
		}
		int right = matrix[0].size(); //右边界
		if ( right == 0) {
			return {};
		}
		vector<int> ans;

		while (true) {  //只要没有报告溢出，就一直循环
			for (int i = left; i < right; i++) { //自左向右
				ans.push_back(matrix[top][i]);
			}
			if (++ top == bottom) break;

			for (int i = top; i < bottom; i++) { //自顶向下
				ans.push_back(matrix[i][right - 1]);
			}
			if (--right == left) break;

			for (int i = right-1; i >= left; i--) { //自右向左
				ans.push_back(matrix[bottom - 1][i]); 
			}
			if (--bottom == top) break;

			for (int i = bottom-1; i >= top; i--) { //自底向上
				ans.push_back(matrix[i][left]);
			}
			if (++left ==right ) break;
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<vector<int>> input = {  };
	auto a = s.spiralOrder(input);

	for (auto line : a) {
		
		cout <<line<< " , ";
	}
	//cout << a << endl;

	return 0;
}

