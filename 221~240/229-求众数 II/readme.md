# 229. 求众数 II

```c++
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

还是使用摩尔投票法，与求1/2的众数不同，因为是要求1/3的众数，所以采用类似三数一组比较判断的方法，三个数中如果某一个数等于众数，则该众数++，如果有一个数不等于任意一个众数。则两个众数的个数要--（因为众数一定大于1/3，所以三数一组时被减的概率小于1/3，所以如果是众数最后一定计数个数大于0）

需要注意的是，这种算法只能保证所有大于1/3的数被选出来，但是不能保证选出来的数都大于1/3，还需要另作判断。

```c++
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> ans;
		int x, y = 0;
		int cx = 0, cy = 0;  //记录cx，cy的个数
		for (auto num : nums)
		{
			if ((cx == 0 || num == x) && num != y)  //注意还要确定num != y，
			{
				cx++;
				x = num;
			}
			else if (cy == 0 || num == y)
			{
				cy++;
				y = num;
			}
			else
			{
				cx--;
				cy--;
			}
		}
		int count = 0;

		//这种算法只能保证所有大于1/3的数被选出来，但是不能保证选出来的数都大于1/3，还需要另作判断
		cx = 0, cy = 0;
		for (auto num : nums) //需确定出现次数是否大于1 / 3，例如有可能一个数出现了前n - 1 一个数在
		{
			if (x == num) cx++;
			if (y == num) cy++;
		}
		if (cx > nums.size() / 3) 
			ans.push_back(x);
		if (cy > nums.size() / 3 && x != y) 
			ans.push_back(y);//要确定x y不相同，主要是防止x，y都为0的情况
			
		return ans;
	}
};
```
