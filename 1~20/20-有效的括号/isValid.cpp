#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
//其实可以增加一个判断：如果栈的深度大于字符串长度的1/2，就返回false。因为当出现这种情况的时候，即使后面的全部匹配，栈也不会为空。

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) {
			return true;
		 }
		

		string t(s.length()+1, ' ');
		int index = 0;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{') {
				t[++index] = c;
			}
			else if (c == ')') {
				if (t[index] == '(')
					index--;
				else {
					return false;
				}
			}
			else if (c == ']') {
				if (t[index] == '[')
					index--;
				else {
					return false;
				}
			}
			else if (c == '}') {
				if (t[index] == '{')
					index--;
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		if (index == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	Solution s = Solution();
	string input = "(((((";
	//vector<string> ans = s.letterCombinations(input);
	cout << s.isValid(input) << endl;

	return 0;
}