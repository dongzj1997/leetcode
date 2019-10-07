#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了91.17%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了76.60%的用户
*/

class Solution {
public:
	string countAndSay(int n) {
		n--;
		string s1 = "1";
		string s2="";
		for (int i = 0; i < n; i++) {
			int len = s1.size();

			char t = s1[0];
			int count = 0;
			for (int j = 0; j < len; j++) {  //对每一个字符
				if (s1[j] != t) {
					string tempstr = to_string(count) + t;
					s2.append(tempstr);
					count = 1;
					t = s1[j];
				}
				else {
					count++;
				}
			}
			string tempstr = to_string(count) + t;
			s2.append(tempstr);
			s1 = s2;
			s2 = "";
			//cout << s1 << endl;
		}
		return s1;
	}
};

int main()
{
	Solution s = Solution();
	string sss = "1234";
	char ss[] = "1234";
	auto ans = s.countAndSay(4);
	
	cout << ans << endl;

	return 0;
}