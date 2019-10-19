#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> ans;
	int climbStairs(int n) {
		ans = vector<int>(n, 0);
		return bp(n);
	}
	int bp(int n) {

		if (n == 1) {
			return 1;
		}
		if (n == 2)
			return 2;

		if (ans[n - 1] == 0) {
			ans[n - 1] =  bp(n - 1) ;
			ans[n - 2] = bp(n - 2);
		}
		
		return ans[n - 1] + ans[n - 2];
		
		
	}

};

int main()
{
	Solution s = Solution();
	vector<int> input = { 1,2,3,4} ;
	auto a = s.climbStairs(44);

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}
	cout << a << endl;

	return 0;
}

