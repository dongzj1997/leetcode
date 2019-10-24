#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int len = s.size();
		if(len == 0 || s[0] == '0') {
			return 0;
		}
		if (len == 1) {
			return 1;
		}
		int pre = 1, cur = 1;
		for (int i = 1; i < len; i++) {
			char t = s[i - 1];
			int temp = cur;//暂存当前的值
			if (s[i] == '0') { //等于0的情况只有和前一个字母结合，否则出错返回0
				if (t == '1' || t == '2')
					cur = pre; //此时不出现新的情况，值没有增加，还有可能减少（如220）
				else
					return 0; //0没有办法解析
			}
			else {
				if (t == '1' || t == '2' && s[i] < '7') {
					cur = pre + cur;
				}
			//	else {
			//		cur = pre;//如果出现28 等情况，不增加结果，但是也不减少结果（227），不做动作
			//	}
			}
			pre = temp;
		}
		return cur;
	}
};

int main()
{
	Solution s = Solution();
	string input = "227";
	auto a = s.numDecodings(input);

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}
	cout << a << endl;

	return 0;
}

