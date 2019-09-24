#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
执行用时 :4 ms, 在所有 C++ 提交中击败了96.57%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了78.13%的用户
*/
/*
这个题使用最常规的竖向对比方法一般来说又快又容易理解，注意边界即可
（先求得最短字符串的长度可以减少大量关于边界的问题）
还可以使用map -reduce的思想利用多台计算机或者多个线程进行加速。
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		uint32_t minlen = INT_MAX;
		string ans = "";

		if (strs.size() == 0)  //防止恶意乱传参数
			return ans;
		if (strs.size() == 1)
			return strs[0];
		for (auto s : strs) {
			minlen = minlen > s.length() ? s.length() : minlen;   //获得字符串最短长度
		}
		for (int i = 0; i < minlen; i++) {
			char t = strs[0][i];
			bool flag = true;
			for (int j = 1; j < strs.size(); j++) {
				if (t != strs[j][i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans += t;
			}
			else {
				break;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<string> input({ "","" });
	cout << s.longestCommonPrefix(input) << endl;

	return 0;
}

