# 978. 最长湍流子数组

```c++
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

 

示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])
示例 2：

输入：[4,8,12,16]
输出：2
示例 3：

输入：[100]
输出：1
 

提示：

1 <= A.length <= 40000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-turbulent-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

按照376题摆动序列的思路来，记录两个数字，同时记录两种情况，并且可以互相转换

```c++
class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		int len = A.size();
		int up = 1, down = 1;
		int ans = 1;
		for (int i = 1; i < len; i++) {
			if (A[i] > A[i - 1]) { 
				up = down + 1; down = 1; 
			}
			else if (A[i] < A[i - 1]) { 
				down = up + 1; up = 1; 
			}
			else  
				up = down = 1;
			ans = max(ans, max(up, down));
		}
		return ans;
	}
};
```

---
