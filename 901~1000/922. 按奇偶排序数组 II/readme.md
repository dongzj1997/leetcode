# 922. 按奇偶排序数组 II

```c++
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

用两个指针记录当前符合条件的位置，当两个指针都不符合条件的话就交换

有点像快排的意思。

```c++
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int len = A.size();
		int i = 0, j = 1;
		while (i < len && j < len) {
			if (i < len && A[i] % 2 == 0) {
				i += 2;
				continue;
			}
			if (j < len && A[j] % 2 == 1) {
				j += 2;
				continue;
			}
			swap(A[i], A[j]);
		}
		return A;
	}
};
```

---
