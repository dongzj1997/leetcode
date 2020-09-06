# 面试题 16.16. 部分排序

```c++
给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

示例：

输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
提示：

0 <= len(array) <= 1000000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sub-sort-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

很巧妙的一道题，分别从左到右 和 从右到左扫一遍，纪录扫描过程中初出现的最大值、最小值，和当前的元素比较。

如果大于、小于当前的元素，说明此处不合理，更新边界。

最后返回边界即可。


```c++
class Solution {
public:
	vector<int> subSort(vector<int>& array) {
		int len = array.size();
		int mx = INT_MIN, mi = INT_MAX;
		int ansl = -1, ansr = -1;
		for (int i = 0; i < len; i++) {
			if (array[i] < mx) ansr = i;
			else mx = array[i];
		}
		for (int i = len - 1; i >= 0; i--) {
			if (array[i] > mi) ansl = i;
			else mi = array[i];
		}
		return { ansl, ansr };
	}
};
```

---
