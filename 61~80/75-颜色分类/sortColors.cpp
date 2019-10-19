class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size()-1, cur=0;
		while (cur<= right) {
			if (nums[cur] == 0) {
				nums[cur] = nums[left];
				nums[left] = 0;
				cur++;
				left++;
			}
			else if (nums[cur] == 1) {
				cur++;
			}
			else { //cur == 2
				nums[cur] = nums[right];
				nums[right] = 2;
				right--;
			}
		}
	}
};