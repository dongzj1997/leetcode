# 面试题03. 数组中重复的数字

```c++
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 

限制：

2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

题目中说了长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内，所以可以遍历数组，

将当前数字当成下标，将所指位置的数取负值，表示该位置已经出现过一次。

如果扫描到某一位置已经是负值了，说明重复的就是该数字。

一点注意：这道题有0的存在，负值还是本身，可以使用特殊标记解决。

```c++
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		bool zero = false;
		for (auto n : nums) {
			nums[abs(n)] *= -1;
			if (nums[abs(n)] < 0) {
				continue;
			}
			else if (nums[abs(n)] > 0)
				return abs(n);
			else {
				if (!zero) zero = true;
				else return 0;
			}
		}
		return 0;
	}
};
```

---



