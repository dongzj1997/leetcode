#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;


//动态规划解法
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了97.93%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了80.24%的用户
*/
/*
class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		int ans = 0;
		//auto a = new int[len];
		
		int* a = (int*)malloc(sizeof(int) * len);
		
		for (int i = 0; i < len; i++) {
			a[i] = 0;
		}
		
		for (int i = 1; i < len; i++) {  //从第二个字符开始
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					a[i] = (i >= 2 ? a[i - 2] : 0) + 2;  //出现()  值为()前的值（如果有）+2  括号是必要的
				}
				else {
					if (i - a[i - 1] > 0 && s[i - a[i - 1] - 1] == '('){
						a[i] = a[i - 1] + ((i - a[i - 1]) >= 2 ? a[i - a[i - 1] - 2] : 0) + 2;
						// 加这一项((i - a[i - 1]) >= 2 ? a[i - a[i - 1] - 2] : 0)是考虑到 (  )  (  (  )  (  )  ) 的情况
						//                                                                 0  2  0  0  2  0  4  8 
					}
				}
				ans = max(ans, a[i]);
			}
		}
		free(a);
		return ans;
	}
};
*/

// 两次遍历的方法
//由于这道题中只有小括号，仔细一想，如果某一段中（）括号数量相等，并且中途不曾出现右括号比左括号多的情况。那么则序列有效。
//由于只在左右括号相等的时候才计算一次结果，所以要左右两次遍历，防止出现左括号多于右括号的情况。
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了81.77%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了98.80%的用户
*/
class Solution {
public:
	int longestValidParentheses(string s) {
		int res = 0;
		int left = 0;
		int mark = 0;
		for (int i = 0; i < s.size(); ++i) {
			int prev_mark = mark;
			mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
			if (mark == 0) {
				if (prev_mark > 0) {
					res = max(i - left + 1, res);
				}
				else {
					left = i + 1;
				}
			}
		}
		mark = 0;
		int right = s.size() - 1;
		for (int i = s.size() - 1; i >= 0; --i) {
			int prev_mark = mark;
			mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
			if (mark == 0) {
				if (prev_mark > 0) {
					res = max(right - i + 1, res);
				}
				else {
					right = i - 1;
				}
			}
		}
		return res;
	}
};


//使用栈的方法：


int main()
{
	Solution s = Solution();
	
	string input = "()())(()())";

	auto ans = s.longestValidParentheses(input);
	                    

	cout << ans << endl;

	return 0;
}
