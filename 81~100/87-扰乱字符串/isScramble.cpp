#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int n = s1.size();
		
		string t1(s1);
		string t2(s2);
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if (t1 != t2) {
			return false;
		}

		if (n <= 3) {
			return true;   //如果n比三小，并且两个字符串排序以后的值完全相等，则一定能成
		}

		for (int i = 1; i < n; ++i) {
			string a1 = s1.substr(0, i); // s1的前i个
			string b1 = s2.substr(0, i); // s2的前i个
			string a2 = s1.substr(i);    // s1的i到末尾
			string b2 = s2.substr(i);    // s2的i到末尾

			string b3 = s2.substr(n - i);  // s2的n-i到末尾
			string b4 = s2.substr(0, n - i);  // s2的前n-i个
			if ((isScramble(a1, b1) && isScramble(a2,b2)) || (isScramble(a1, b3) && isScramble(a2, b4))) {
				return true;
			}
		}
		return false;
	}
};

int main()
{

	Solution s = Solution();

	//vector<vector<int>> input = { {0},{0},{1},{0} };
	//vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<int> input = { 2,5,6,0,0,1,2 };
	auto a = s.isScramble("abcde", "caebd");

	//for (auto line : a) {
	//	for (auto c : line) {
	//		cout << c <<"" ;
	//	}
	//	cout << endl;
	//}

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	cout << a << endl;

	return 0;
}