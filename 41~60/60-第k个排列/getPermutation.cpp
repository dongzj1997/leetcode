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
	string getPermutation(int n, int k)
	{
		string ans;
		if (n == 0)
			return ans;
		else if (n == 1)
			return "1";
		vector<int> vec_cofficient = { 1,1,2,6,24,120,720,5040,40320,362880 };
		int cur = 0;

		vector<char> single;
		for (int i = 0; i < n; i++)
			single.push_back('1' + i); //123456.....

		for (int i = 0; i < n; i++)	//从0开始，往后每一位进行循环
		{
			int curpos = n - i - 1;	//根据当前位置匹配vec_cofficient里的值
			for (int j = 0; j < n; j++)
			{
				if (cur + vec_cofficient[curpos] < k)	//进行累加，如果小于K就继续加
				{
					cur += vec_cofficient[curpos];
					continue;
				}
				else	//如果小于K则收手，把对应的值加进去，同时把single里这个用过的值删掉
				{
					ans.push_back(single[j]);
					single.erase(single.begin() + j);
					break;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<vector<int>> input = { {1,4},{0,4} };
	auto a = s.getPermutation(3,3);

	/*for (auto line : a) {
		for (auto c : line) {
			cout << c << " , ";
		}
		cout << endl;
	}*/

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	cout << a << endl;

	return 0;
}

