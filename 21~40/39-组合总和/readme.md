# 39. 组合总和

```c++
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
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
```

---
