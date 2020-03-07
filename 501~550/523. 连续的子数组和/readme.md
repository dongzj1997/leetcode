# 523. 连续的子数组和

```c++
给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

示例 1:

输入: [23,2,4,6,7], k = 6
输出: True
解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
示例 2:

输入: [23,2,6,4,7], k = 6
输出: True
解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
说明:

数组的长度不会超过10,000。
你可以认为所有数字总和在 32 位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

和第525题一个套路，别忘了初始化

```c++
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		map<int, int> mp;
        for(int i = 0; i < nums.size()-1; i++) 
            if(nums[i] == 0 && nums[i+1] == 0) return true;
        if(k == 0) return false;
        k = abs(k);
		int sum = 0, ans = 0,len = nums.size();
        if(len <2) return false;
        mp[0] = -1; //别忘了初始化
		for (int i = 0; i < len; i++) {
			sum += nums[i];
			sum %= k;
			if (k == 0) return true;
			if (mp.count(sum) == 0)
				mp[sum] = i;
			else
                if(i - mp[sum] > 1)
				    return true;
		}
		return false;
	}
};
```

---



