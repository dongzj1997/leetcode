#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	vector<string> ans;
	string ss;
	int len;
	int split[3] = { 0 };

	vector<string> restoreIpAddresses(string s) {
		ss = s;
		len = s.size();
		
		dfs(0);
		return ans;
	}

	void dfs(int deep) {
		if (deep == 3) {
			if (len - split[2] > 3 || split[2] >= len)
				return;
			if (valid(ss.substr(split[2], len - split[2] ))) {
				gen_ans();
			}
			return;
		}
		for (int i = 1; i <= 3; i++) {
			int start = deep == 0 ? 0 : split[deep - 1] ;
			if (start+i < len &&valid(ss.substr(start, i))){
				split[deep] = start+i;
				dfs(deep+1);
			}
		}
	}

	void gen_ans() {
		string temp(len + 3,'0');
		int j = 0;//记录第j个点的位置
		for (int i = 0; i < len; i++) {
			if (j<3 && i == split[j]) {
				temp[i+j] = '.';
				j++;
			}
			temp[i + j] = ss[i];
		}
		ans.push_back(temp);
	}

	bool valid(const string& s) {
		if (s[0] == '0') {
			if (s.size() > 1) {
				return false;
			}
		}
		int val = stoi(s);
		if (val >= 0 && val <= 255) 
			return true;
		else
			return false;
	}
};
int main()
{
	Solution s = Solution();
	string input = "010010";
	auto a = s.restoreIpAddresses(input);

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}

	for (auto t : a) {
		cout << t << " , ";
	}

	//cout << a << endl;

	return 0;
}

