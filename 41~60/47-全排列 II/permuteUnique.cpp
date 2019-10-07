#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
执行用时 :8 ms, 在所有 C++ 提交中击败了99.92%的用户
内存消耗 :9.4 MB, 在所有 C++ 提交中击败了57.49%的用户
*/
class Solution {
public:
	vector<int> temp2;
	//vector<vector<int>> res2;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> temp;
		vector<vector<int>> res;
		vector<bool> visited(n, false);
		DFS(nums, temp, res, 0, visited);
		return res;
	}

	void DFS(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int cursize, vector<bool>& visited) {
		if (cursize == nums.size()) {
			res.push_back(temp);

			for (auto ss : temp2) {
				cout << ss << " -> ";
			}
			cout << endl;
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])  //保证了相同的排列只有倒叙访问一种情况，如1，1，1，2  ，前三个111访问顺序只能是3，2，1  （如果前一个相同元素访问过，直接continue）
					continue;                                            // 如果改为 ！visited[i - 1] ，则访问顺序只能是1，2，3 (前一个相同元素还没有访问，则直接continue)
				temp.push_back(nums[i]);//记录值                              //任何一次continue都会导致最终的元素不够，注定无结果，可以直接改为return；
				temp2.push_back(i);//记录访问顺序
				visited[i] = true;
				DFS(nums, temp, res, cursize + 1, visited);

				temp.pop_back();
				temp2.pop_back();
				visited[i] = false;
			}
		}
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 0,1,0,0,9 };
	auto a = s.permuteUnique(input);

	for (auto t : a) {
		for (auto tt : t) {
			cout << tt << " , ";
		}
		cout << endl;
	}
	//cout << a << endl;

	return 0;
}

