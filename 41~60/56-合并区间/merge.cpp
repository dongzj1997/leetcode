#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


/*
执行用时 :16 ms, 在所有 C++ 提交中击败了99.61%的用户
内存消耗 :12.3 MB, 在所有 C++ 提交中击败了5.08%的用户
*/

class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int size = intervals.size();
		if (size <= 1)
			return intervals;

		vector<vector<int> > res;

		sort(intervals.begin(), intervals.end(),cmp);
		int left = intervals[0][0];
		int right = intervals[0][1];

		for (int i = 0; i < size;i++) {
			if (intervals[i][0] <= right) {
				right = right > intervals[i][1] ? right : intervals[i][1];
			}
			else {
				res.push_back({ left,right });
				left = intervals[i][0];
				right = intervals[i][1];
			}
		}
		res.push_back({ left,right });
		return res;


	}
};


int main()
{
	Solution s = Solution();
	vector<vector<int>> input = { {1,4},{0,4} };
	auto a = s.merge(input);

	for (auto line : a) {
		for (auto c : line) {
			cout << c << " , ";
		}
		cout << endl;
	}

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	//cout << a << endl;

	return 0;
}

