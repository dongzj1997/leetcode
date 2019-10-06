#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了98.13%的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了85.75%的用户
*/
class Solution {
public:
	vector<int> candidates;
	vector<vector<int>> res; //最终结果
	vector<int> path;  //存储路径

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//先将所给的数据排序，便于后续剪枝操作
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates; //赋值类变量，减少参数传递操作。
		DFS(0, target);
		return res;
	}
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
			path.push_back(candidates[i]);
			DFS(i, target - candidates[i]);
			path.pop_back();
		}
	}

};

int main()
{
	Solution s = Solution();
	vector<int> input = { 2,3,6,7 };
	auto a = s.combinationSum(input,7);
	//cout << a << endl;

	for (auto t : a) {
		for (auto tt : t) {
			cout << tt << " , ";

		}
		cout << endl;
	}

	return 0;
}