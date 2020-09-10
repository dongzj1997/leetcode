# 1508. 子数组和排序后的区间和

```c++
给你一个数组 nums ，它包含 n 个正整数。你需要计算所有非空连续子数组的和，并将它们按升序排序，得到一个新的包含 n * (n + 1) / 2 个数字的数组。

请你返回在新数组中下标为 left 到 right （下标从 1 开始）的所有数字和（包括左右端点）。由于答案可能很大，请你将它对 10^9 + 7 取模后返回。

 

示例 1：

输入：nums = [1,2,3,4], n = 4, left = 1, right = 5
输出：13 
解释：所有的子数组和为 1, 3, 6, 10, 2, 5, 9, 3, 7, 4 。将它们升序排序后，我们得到新的数组 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标从 le = 1 到 ri = 5 的和为 1 + 2 + 3 + 3 + 4 = 13 。
示例 2：

输入：nums = [1,2,3,4], n = 4, left = 3, right = 4
输出：6
解释：给定数组与示例 1 一样，所以新数组为 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标从 le = 3 到 ri = 4 的和为 3 + 3 = 6 。
示例 3：

输入：nums = [1,2,3,4], n = 4, left = 1, right = 10
输出：50
 

提示：

1 <= nums.length <= 10^3
nums.length == n
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-of-sorted-subarray-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

看了一眼题，感觉和`373. 查找和最小的K对数字`，比较像，可以查看no.373的[解题](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/)

思路一样，使用优先队列，还要记住优先队列的下标走到哪了。

```c++
class Solution {
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		int M = 1e9 + 7;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		for (int i = 0; i < n; i++) 
			q.emplace(nums[i], i);
		int cnt = 0;
		long long ans = 0;
		while (cnt < right) {
			auto cur = q.top();
			cnt++;
			q.pop();
			if (cnt >= left) 
				ans = (ans + cur.first) % M;
			if (cur.second < n - 1) 
				q.emplace(cur.first + nums[cur.second + 1], cur.second + 1);
		}
		return ans;
	}
};

```

---
