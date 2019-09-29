class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
				lo = mid + 1;
			else
				hi = mid;
		}
		return lo == hi && nums[lo] == target ? lo : -1;
	}
};
/*
作者：LukeLee
链接：https ://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

代码十分的简洁，
nums[0] <= nums[mid]（0 - mid不包含旋转）且nums[0] <= target <= nums[mid] 时 high 向前规约；
nums[mid] < nums[0]（0 - mid包含旋转），target <= nums[mid] < nums[0] 时向前规约（target 在旋转位置到 mid 之间
nums[mid] < nums[0]，nums[mid] < nums[0] <= target 时向前规约（target 在 0 到旋转位置之间）
其他情况向后规约
也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid] 三项均为真或者只有一项为真时向后规约。

(nums[0] <= target)， (target <= nums[i]) ，(nums[i] < nums[0])，现在我们想知道这三项中有哪两项为真（明显这三项不可能均为真或均为假（因为这三项可能已经包含了所有情况））

使用 “异或” 操作可以轻松的得到上述结果（两项为真时异或结果为假，一项为真时异或结果为真，可以画真值表进行验证）

之后我们通过二分查找不断做小 target 可能位于的区间直到 low==high，此时如果 nums[low]==target 则找到了，如果不等则说明该数组里没有此项。
*/