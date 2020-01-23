# 324. 摆动排序 II

```c++
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

示例 1:

输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
示例 2:

输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
说明:
你可以假设所有输入都会得到有效的结果。

进阶:
你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wiggle-sort-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		//使用nth_element 函数寻找第 n/2 大元素
		nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
		int mid = nums[n / 2];

		// 3-way-partion
		int i = 0;
		int j = 0;
		int k = n - 1;

		vector<int> map(n, 0);
		for (int i = 0; i < n; i++) {
			map[i] = (2 * (i)+1) % (n | 1);
		}


		while (j <= k) {
			if (nums[map[j]] > mid) {
				swap(nums[map[i]], nums[map[j]]);
				++i;
				++j;
			}
			else if (nums[map[j]] < mid) {
				swap(nums[map[j]], nums[map[k]]);
				--k;
			}
			else {
				++j;
			}
		}
	}
};
```

---

1. 使用使用nth_element 函数寻找第 n/2 大元素

2. 将整个数组按照于n/2 大元素分配到两边，参考 [75 题](https://leetcode-cn.com/problems/sort-colors/comments/64938 )。三向切分注意，我们需要把比 mid 大的数安排到 mid 左边，比 mid 小的数安排到 mid 右边，最后数组大概像是这样 [++++++,key,-------].

3. 交替排列即可。

> 怎么把一个三向切分好的数组变成摆数组，可以使用“索引”映射这个方法（有人称为索引改写，有人称为虚拟索引，怎么说都行，我也是从大神那里学习过来的），假设数组大小是 6

```c
 0 1 2 3 4 5
[1 1 1 3 4 5]

[3 1 4 1 5 1]
0->1
1->3
2->5
3->0
4->2
5->4
```

>意思是说，做映射后，把位置 0 的元素安排到位置 1 上，把位置 1 安排到位置 3 上，位置 2 安排到位置 5 上，位置 3 安排到位置 0 上，位置 4 安排到位置 2 上，而位置 5 安排到位置 4 上。这样安排后，数组就变以了摆动数组。
>实际上，我们可以把三向切分的过程，和数组索引映射合并到一起完成。在程序里，我们定义映射后的数组为 a(i) = nums[(2*i+1) % (n|1)]，在三向切分的时候，对 a(i) 进行操作即可。
