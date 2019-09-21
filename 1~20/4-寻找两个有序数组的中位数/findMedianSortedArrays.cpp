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

/*

int main()
{
	Solution s = Solution();
	vector<int> a({ 2,3}) ;
	vector<int> b({ 1});
	double ans = s.findMedianSortedArrays(a,b);
	cout << ans << endl;
}
*/
