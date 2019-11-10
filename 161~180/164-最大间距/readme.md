# 164-最大间距

```c++
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-gap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Bucket {
public:
	bool used = false;
	int minval = INT_MAX;       
	int maxval = INT_MIN;       
};

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2)
			return 0;

		int minVal = *min_element(nums.begin(), nums.end());
		int	maxVal = *max_element(nums.begin(), nums.end());

		int bucketSize = max(1, (maxVal - minVal) / ((int)nums.size() - 1));        // 每个桶的区间长度
		int bucketNum = (maxVal - minVal) / bucketSize + 1;                         // 桶的个数
		vector<Bucket> buckets(bucketNum);

		for (auto num : nums) {
			int bucketIdx = (num - minVal) / bucketSize;                          // 计算出应该放在第几个桶中
			buckets[bucketIdx].used = true;
			buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
			buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
		}

		int prevBucketMax = minVal, maxGap = 0;
		for (auto bucket : buckets) {
			if (!bucket.used)
				continue;

			maxGap = max(maxGap, bucket.minval - prevBucketMax);
			prevBucketMax = bucket.maxval;
		}

		return maxGap;
	}
};
```

---

## 解答：使用桶排序，使排序的算法复杂度下降到O(n)

### 本题中的“桶”，类

```C++
class Bucket {
public:
	bool used = false;
	int minval = INT_MAX;       
	int maxval = INT_MIN;       
};
```

因为本题只关心每个桶中的最大值和最小值，所以每个桶不必记录桶中的所有数据值，只需要记录桶中的最大值和最小值即可，为了防止有些桶为空的情况，不好比较最大最小值，使用`bool used = false;`记录这个通中有没有数据。

### 详细思路

首先，我们可以知道相邻的最大间距一定不小于该数组的最大值减去最小值除以间隔个数，假设原始数组中的所有值呈等差数列分步，此时最大间隔一定最小，只要有一个数出现波动，此时最大间隔就一定大于均匀间隔，所以可以设置桶的大小为均匀间隔。 计算方法为`int bucketSize = max(1, (maxVal - minVal) / ((int)nums.size() - 1));`

有了桶的大小，需要多少个桶很容易求出，为`int bucketNum = (maxVal - minVal) / bucketSize + 1;`。

接下来将数据放入桶中，其实只是一个比较的过程，求出每个桶的最大值和最小值。

使用后一个桶的最小值和前一个桶的最大值比较（如果桶没有使用，则跳过），得出最后的结果。
