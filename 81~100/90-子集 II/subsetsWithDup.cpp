class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans = { {} };//一定要保证为{{}},这时候的size = 1
		if (nums.size() == 0) 
			return ans;
		sort(nums.begin(), nums.end());     // 在遍历之前进行排序
		int start=0;
		for (int i = 0; i < nums.size(); i++) {   //从第一个到最后一个元素，分别加入到结果中
			int len = ans.size(); //当前结果中的元素数量
			if (i > 0 && nums[i] != nums[i - 1])
				start = 0;          // 新数字，全部遍历，将start置为0
			for (int j = start; j < len; j++) {
				vector<int> tmp = ans[j];
				tmp.push_back(nums[i]);
				ans.push_back(tmp);  //插入到结果中
			}
			start = ans.size() - (len - start); // 重复数字,从上一轮新添加的部分开始（很关键）
		}

		return ans;
	}
};