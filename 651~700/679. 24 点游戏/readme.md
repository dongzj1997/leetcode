# 679. 24 点游戏

```c++
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/24-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

主要思路：

每次从数组中选出两个数，然后将其他数和这两个数的运算值作为新的数组，进行下一轮遍历，如果数组为大小1的话，判单是否为24。

总体来说写的很顺，主要注意两点：

1. 24点期间出现小数也是可以的，比如`1,3,4,5 :  6/(1-3/4)`

2. 既然出现了小数，所以最后比较的时候不能按照int比较，要使用`abs(nums[0] - 24.0) <= 1e-6;`

```c++
class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double> n;
		for (auto t : nums) {
			n.push_back((double)t);
		}
		return judgePoint24(n);
	}
	bool judgePoint24(vector<double>& nums) {
		int len = nums.size();
		if (len == 1) return abs(nums[0] - 24.0) <= 1e-6;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j) continue;
				vector<double> t;
				for (int k = 0; k < len; k++) {
					if (k != i && k != j) {
						t.push_back(nums[k]);
					}
				}
				t.push_back(nums[i] + nums[j]);
				if (judgePoint24(t)) return true;
				t.pop_back();

				t.push_back(nums[i] - nums[j]);
				if (judgePoint24(t)) return true;
				t.pop_back();

				t.push_back(nums[i] * nums[j]);
				if (judgePoint24(t)) return true;
				t.pop_back();

				if (nums[j] != 0) {
					t.push_back(nums[i] / nums[j]);
					if (judgePoint24(t)) return true;
					t.pop_back();
				}
			}
		}
		return false;
	}
};
```

---



