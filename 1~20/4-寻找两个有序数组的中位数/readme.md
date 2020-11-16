# 4. 寻找两个正序数组的中位数

```c++
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //一方面 防止出现数组2越界的问题，另一方面，将数组1变短可以使搜索速度变快
		{
			return findMedianSortedArrays(nums2, nums1);
		}


		int c1, c2; // 分别为第i个vector的分割点
		int left = 0, right = 2 * n;  //当前二分查找的左边界和右边界,由于插入虚拟的# 所以最大的下标为2n
		int LMax1=0, LMax2=0, RMin1 = 0, RMin2 = 0;  //分别为每次分割以后数组1和2的左右元素
		while (left <= right) {
			c1 = (left + right) / 2;
			c2 = (n + m) - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2]; //数组1 的所有元素都大于中位数
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2]; //数组1 的所有元素都小于中位数
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];//数组2 的所有元素都大于中位数
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];//数组2 的所有元素都小于中位数

			if (LMax1 > RMin2) {
				right = c1 - 1;
			}
			else if (LMax2 > RMin1) {
				left = c1 + 1;
			}
			else {
				break; // 此时数组1和2的左半边小于数组1和2的右半边，说明已经找到合适的分割点c
			}
		}

		return ((LMax1 > LMax2 ? LMax1 : LMax2) + (RMin1 > RMin2 ? RMin2 : RMin1)) / 2.0;  //输出左边的最大值和右边的最小值
	}
};
```

---
