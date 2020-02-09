# 496-下一个更大元素 I

```c++
给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

从后往前遍历，栈中的元素严格递增

如果当前要插入的元素大于栈顶，则弹出栈顶元素，直到栈为空或者栈顶元素大于当前值

```c++
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		unordered_map<int, int> mp;
		stack<int> s;
		for (int i = nums2.size() - 1; i >= 0; i--) {
			while (1) {
				if (s.empty()) {
					mp[nums2[i]] = -1;
					s.push(nums2[i]);
					break;
				}
				else if (s.top() > nums2[i]) {
					mp[nums2[i]] = s.top();
					s.push(nums2[i]);
					break;
				}
				else {
					s.pop();
				}
			}

		}
		for (auto n : nums1) {
			ans.push_back(mp[n]);
		}
		return ans;
	}
};
```

---



