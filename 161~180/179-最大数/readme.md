# 179. 最大数

```c++
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题：使用自定义comp函数的sort

既然要比较 3,30,34,5,9 等，遵循以下策略

1. 先将数组转为字符串 （自己写是没有转，使用数组比较的，但是太繁琐，不建议）

2. 从数组的最高位开始比较，相等则比较下一位，不等则返回比较的大小。

3. 如果一个数（假设为a）比较完后另一个数（假设为b）还有剩余（假设为c），则比较（a，c）的大小。

```c++
bool comp(int compA, int compB) {
	int a = compA, b = compB;


	if (a == b)
		return 0;
	if (a == 0 || b == 0)
		return a > b;
	int t1 = 1, t2 = 1;
	int len1 = 1, len2 = 1;
	while (a >= t1 *10) {
		t1 *= 10;
		len1++;
	}
	while (b >= t2 * 10) {
		t2 *= 10;
		len2++;
	}
	int v1, v2;
	while (len1 != 0 && len2 != 0) {
		v1 = a / t1;
		a = a % t1;
		t1 = t1 / 10;
		len1--;

		v2 = b / t2;
		b = b % t2;
		t2 = t2 / 10;
		len2--;

		if (v1 != v2) {
			return v1 > v2;
		}
	}
	if (len1 == 0) {
		if (b < t2) {
			return 1;
		}
		return comp(compA,b);
	}
	if (len2 == 0) {
		if (a < t1) {
			return 0;
		}
		return comp(a, compB);
	}
	return 1;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string ans = "";
		sort(nums.begin(), nums.end(), comp);

		for (int i : nums) {
			ans += to_string(i);
		}
        if (ans[0] == '0') {
			return "0";
		}
		return ans;
	}
};
```

---

## 另一种更巧妙的解法

自定义一种排序方式 比较 s1 + s2 和 s2 + s1,这样就避免了两个数长度不相等的问题。

```python
s = ''
for i in range(len(nums)-1):
    for j in range(i+1,len(nums)):
        if int(str(nums[i])+str(nums[j])) < int(str(nums[j])+str(nums[i])):
            nums[i],nums[j] = nums[j],nums[i]
for x in (nums):
    s += str(x)
return str(int(s))
```