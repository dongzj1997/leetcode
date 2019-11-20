# 239. 滑动窗口最大值

```c++
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

 

进阶：

你能在线性时间复杂度内解决此题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析：使用窗口元素保持递减的方法在线性时间复杂度内解决此题

因为需要的是窗口内的最大值，所以只要保证窗口内的值是递减的即可（如果窗口中的值是U形排列的，中间的值一定不可能是结果），小于新加入的值全部弹出。

此外，每次移动以后还要保证窗口的第一个元素是否还在窗口中。

```c++
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		vector<int> slidewindows; //slidewindows存储的是滑动窗口中的下标，保持递减
		int len = nums.size();

		if (k == 0 || len == 0)
			return ans;


		for (int i = 0; i < k; i++) { //窗口初始化
			while (slidewindows.size() > 0 && nums[slidewindows.back()] <= nums[i]) { 
				slidewindows.pop_back(); //为了保持窗口元素的递减，将所有小于新加入元素 的元素删掉
			}
			slidewindows.push_back(i); //这样就保证了新加入元素一定在最后面
		}
		ans.push_back(nums[slidewindows[0]]);  //添加第一个答案

		for (int i = k; i < len; i++) {
			while (slidewindows.size() != 0 && nums[slidewindows.back()] <= nums[i]) {
				slidewindows.pop_back(); //同理
			}
			slidewindows.push_back(i);//新加入元素一定在最后面
			if (slidewindows[0] <= i - k) //检测当前窗口的第一个元素（最大的）是否还在窗口中（因为窗口一次只移动一格，所以检测一次就好）
				slidewindows.erase(slidewindows.begin());
			ans.push_back(nums[slidewindows[0]]);//添加答案
		}
		return ans;
	}
};
```

---

