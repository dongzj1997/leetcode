class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) {
			return nums[0];
		}

		int ans = nums[0];
		//int* sum = (int*)malloc(n * sizeof(int));
		int sum = nums[0];
		for (int i = 1; i < n; i++) {
			sum = nums[i] + sum > nums[i] ? nums[i] + sum : nums[i];
			ans = ans > sum ? ans : sum;
		}
		//free(sum);
		return ans;
	}
};