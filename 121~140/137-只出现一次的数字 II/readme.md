# 137. 只出现一次的数字 II

```c++
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int numsSize = nums.size();
		int s[32] = { 0 };
		int res = 0;
		for (int i = 0; i < numsSize; i++) {
			for (int j = 0; j < 32; j++) {
				s[j] += (((unsigned int)nums[i]) >> j) % 2;
				if (s[j] == 3)
					s[j] = 0;
			}
		}
		
		unsigned int t = 1; //使用无符号整形

		for (int j = 0; j < 32; j++) {
			if (s[j])
				res |=  t << j;
		}
		return res;
	}
};
```

---

对于每一位的二进制的1和0累加起来必然是3N或者3N+1， 因为3N代表目标值在这一位没贡献，3N+1代表目标值在这一位有贡献(=1)，然后将所有有贡献的位|起来就是结果。这样做的好处是如果题目改成K个一样，只需要把代码改成cnt%k，比较通用

---

位运算版本

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto num : nums)
        {
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }
        return a;
    }
};
```
