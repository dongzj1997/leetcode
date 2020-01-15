# 300. 最长上升子序列

```c++
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
//O(NlogN)的方法
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		/**
		dp[i]: 所有长度为i+1的递增子序列中, 最小的那个序列尾数.
		由定义知dp数组必然是一个递增数组, 可以用 maxL 来表示最长递增子序列的长度.
		对数组进行迭代, 依次判断每个数num将其插入dp数组相应的位置:
		1. num > dp[maxL], 表示num比所有已知递增序列的尾数都大, 将num添加入dp
		   数组尾部, 并将最长递增序列长度maxL加1
		2. dp[i-1] < num <= dp[i], 只更新相应的dp[i]
		**/
		int maxL = 0; //最长递增序列长度
		int len = nums.size();
		vector<int> dp(len, 0);
		for (int num : nums) {
			// 二分法查找, 也可以调用库函数如binary_search
			int lo = 0, hi = maxL;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (dp[mid] < num)
					lo = mid + 1;
				else
					hi = mid;
			}
			dp[lo] = num;
			if (lo == maxL)
				maxL++;
		}
		return maxL;
	}
};

```

---

```c++

//O(n*n)的解法 简单易懂
//vector<int> dp(len,1 );中存储的是以该数字结尾的最长子序列的长度

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ans = 0;
		int temp;
		int len = nums.size();
		vector<int> dp(len,1 );
		for (int i = 0; i < len; i++) {
			temp = 1;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					temp = max(temp, dp[j] + 1);
				}
			}
			dp[i] = temp;
			ans = max(temp, ans);
		}
		return ans;
	}
};

```

---

两种方法！
