#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了97.24%的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了85.50%的用户
*/
class Solution {
public:
	vector<int> candidates;
	vector<vector<int>> res; //最终结果
	vector<int> path;  //存储路径

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
			if (i > start && candidates[i] == candidates[i - 1]) { // 这里保证了如果有重复元素时，直接跳过，
				//除非是第一个元素，
				continue;
			}
			path.push_back(candidates[i]);
			DFS(i+1, target - candidates[i]);
			path.pop_back();
		}
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 10,1,2,7,6,1,5 };
	auto a = s.combinationSum2(input,8);
	//cout << a << endl;

	for (auto t : a) {
		for (auto tt : t) {
			cout << tt << " , ";

		}
		cout << endl;
	}

	return 0;
}