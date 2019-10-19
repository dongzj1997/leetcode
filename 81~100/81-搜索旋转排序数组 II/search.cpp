class Solution {
public:
//每次二分，左半部分和右半部分至少有一边是有序的，可以分成两种情况：（！注意小心的处理边界）
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			//处理重复数字
			while (left < right && nums[left] == nums[left + 1]) ++left;
			while (left < right && nums[right] == nums[right - 1]) --right;
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return true;

			//左半部分有序
			if (nums[mid] >= nums[left]) {
				if (target < nums[mid] && target >= nums[left]) 
					right = mid - 1;//target落在左半边
				else 
					left = mid + 1;//target落在右半边
			}
			else {//右半部分有序
				if (target > nums[mid] && target <= nums[right]) 
					left = mid + 1;//target落在右半边
				else 
					right = mid - 1;//target落在左半边
			}
		}
		return false;
	}
};