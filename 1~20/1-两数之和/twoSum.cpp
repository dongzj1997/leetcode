class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> result_map;
        for(int i = 0;i<nums.size();i++){
            if (result_map.count(nums[i]))
				return {result_map[nums[i]],i };
            result_map[target-nums[i]] = i;
        }
        return {};
    }
};
