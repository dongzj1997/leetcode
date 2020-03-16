# 670. 最大交换

```c++
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先排序，找出第一个与原数字不同的数，然后从后往前找出交换的那个数，交换以后就是答案

```c++
class Solution {
public:
	int maximumSwap(int num) {
		if (num <= 9) return num;
		string s = to_string(num);
		string t(s);
		sort(t.begin(), t.end(), [](char a, char b) {return a > b; });
		int index1 = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (t[i] != s[i]) {
				index1 = i;
				break;
			}
		}
		if (index1 == -1) return num;
		for (int i = s.size() -1; i >=index1+1; i--)
		{
			if (s[i] == t[index1]) {
				swap(s[i], s[index1]);
				break;
			}
		}
		return stoi(s);
	}
};
```

---



