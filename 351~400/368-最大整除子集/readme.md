# 368. 最大整除子集

```c++
给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

 

示例 1:

输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)
示例 2:

输入: [1,2,4,8]
输出: [1,2,4,8]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-divisible-subset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用动态规划来解决这个问题

先对数据从小到大排序。

数据结构： `vector<int> dp(len, 1);` 表示nums中第i个数结尾的子集最大长度  
`vector<int> thread(len, 0);` 表示第i个数上一个数的位置

二次循环即可。

```c++
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int len = nums.size();
		int maxLen = 0, index = 0;
		vector<int> thread(len, 0);
		/*for (int i = 0; i < len; i++) {
			thread[i] = i;
		}*/
		if (len == 0)
			return {};
		if (len < 2 )
			return { nums };

		vector<int> dp(len, 1);
		sort(nums.begin(), nums.end());
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if ((nums[i] % nums[j]) == 0 && dp[j]>= dp[i]) {
					dp[i] = dp[j] + 1;
					thread[i] = j;
				}
			}

			if (dp[i] > maxLen) {
				maxLen = dp[i];
				index = i;
			}

		}

		//倒序
		vector<int> ans;
		for (int i = index; maxLen != 0; i = thread[i]) {
			ans.insert(ans.begin(),nums[i]);
			maxLen--;
		}
		return ans;
	}
};
```

---



