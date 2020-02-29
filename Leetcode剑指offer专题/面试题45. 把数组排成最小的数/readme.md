# 面试题45. 把数组排成最小的数

```c++
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

 

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
通过次数1,188提交次数2,139

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

！！！！  `return sa + sb < sb + sa;`

就是比较先a后b和先b后a哪个小！！！！

```c++
class Solution {
public:
	static bool cmp(int a, int b) {
		string sa = to_string(a);
		string sb = to_string(b);

		return sa + sb < sb + sa;
	}
	string minNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string ans;
		for (int a : nums)
			ans += to_string(a);
		return ans;
	}
};
```

---



