#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		// 记录最短子串的开始位置和长度
		int start = 0, minLen = INT_MAX;
		int left = 0, right = 0;

		map<char, int> window;
		map<char, int> needs;
		for (char c : t) 
			needs[c]++;

		int match = 0;

		while (right < s.size()) {
			char c1 = s[right];
			if (needs.count(c1)) { //表示需要这个字符
				window[c1]++;   //该字符已经找到的个数+1，，！！！注意，如果需要3个，这时找到第四个，也会+1
				if (window[c1] == needs[c1])
					match++; // 记录 window 中已经有多少字符符合要求了（数量达到）
			}
			right++;

			while (match == needs.size()) {  //全部找到
				if (right - left < minLen) {
					// 更新最小子串的位置和长度
					start = left;
					minLen = right - left;
				}
				char c2 = s[left];  //不断缩小
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2])
						match--;
				}
				left++;//不断缩小
			}
		}
		return minLen == INT_MAX ?
			"" : s.substr(start, minLen);
	}
};

int main()
{

	Solution s = Solution();
	//vector<vector<int>> input = { {0},{0},{1},{0} };
	vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
	auto a = s.minWindow("a","aa");

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