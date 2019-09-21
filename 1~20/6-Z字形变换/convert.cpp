#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1)
			return s;
		vector<vector<char> > ans(numRows);
		
		int len = s.size();
		string ss(len, '0');
		int t = 2 * numRows - 2;
		for (int i = 0; i < len; i++) {
			if (i % t < numRows) {
				ans[i % t].push_back(s[i]);
			}
			else {
				ans[t- i % t ].push_back(s[i]);
			}
		}
		int k = 0;
		for (int i = 0; i < numRows; i++) {
			vector<char> tt = ans[i];
			int max = tt.size();
			for (int j = 0; j < max; j++) {
				//printf("%c", tt[j]);
				ss[k++] = tt[j];
			}
		}
		return ss;
		
	}
};



int main()
{
	Solution s = Solution();
	string a = "A";
	string ans = s.convert(a,1);
	cout << ans << endl;

	return 0;
}
/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
*/
/*
本题思路较为简单，创建一个二维的vector ，遍历原始字符串，通过求模运算将原始字符串分配到二位vector中，
再按照次序输出这个二维vrctor即可
空间复杂度为O(n) 时间复杂度也为O(n)

除此之外，还可以使用flag指针来变换输入顺序或者直接计算位置，按行访问来求得结果
*/


