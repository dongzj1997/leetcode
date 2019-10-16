#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
	int state = 0;
	int transfer[9][5] ={ 
		{ 0, 1, 6, 2,-1},
		{-1,-1, 6, 2,-1},
		{-1,-1, 3,-1,-1},
		{ 8,-1, 3,-1, 4},
		{-1, 7, 5,-1,-1},
		{ 8,-1, 5,-1,-1},
		{ 8,-1, 6, 3, 4},
		{-1,-1, 5,-1,-1},
		{ 8,-1,-1,-1,-1}  
	};


	bool isNumber(string s) {

		for (auto c : s) {
			int id = getId(c);
			if (id == -1) 
				return false;
			state = transfer[state][id];
			if (state ==-1) 
				return false;
		}

		if (state == 3 || state == 5 || state == 6 || state == 8) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int getId(char c) {
		if (c >= 48 && c <= 57) 
			return 2;
		switch (c) {
			case ' ': return 0;
			case '+':
			case '-': return 1;
			case '.': return 3;
			case 'e': return 4;
			default:
				return -1;
		}
	}
};
/*
state	blank	+/-	  0-9	   .	   e	 other
0	      0	      1	   6	    2	  -1      -1
1	     -1	     -1	   6	    2	  -1      -1
2	     -1	     -1	   3	   -1	  -1      -1
3	      8	     -1	   3	   -1	   4	  -1
4	     -1	      7	   5	   -1	  -1      -1
5	      8	     -1	   5	   -1	  -1      -1
6	      8	     -1	   6	    3	   4	  -1
7	     -1	     -1	   5	   -1	  -1      -1
8	      8	     -1	  -1	   -1	  -1      -1
状态图详见https://pic.leetcode-cn.com/0683d701f2948a2bd8c235867c21a3aed5977691f129ecf34d681d43d57e339c-DFA.jpg						 
*/


int main()
{

	Solution s = Solution();
	//vector<vector<int>> input = { {0},{0},{1},{0} };
	string input = "1 ";
	auto a = s.isNumber(input);

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