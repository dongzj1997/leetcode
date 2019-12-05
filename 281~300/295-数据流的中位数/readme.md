# 295. 数据流的中位数

```c++
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

在数据流中，数据会不断涌入结构中，那么也就面临着需要多次动态调整以获得中位数。 因此实现的数据结构需要既需要快速找到中位数，也需要做到快速调整。

首先能想到就是二叉搜索树，在平衡状态下，树顶必定是中间数，然后再根据长度的奇偶性决定是否取两个数。

此方法效率高，但是手动编写较费时费力。

根据只需获得中间数的想法，可以将数据分为左右两边，一边以最大堆的形式实现，可以快速获得左侧最大数， 另一边则以最小堆的形式实现。其中需要注意的一点就是左右侧数据的长度差不能超过1。 这种实现方式的效率与AVL平衡二叉搜索树的效率相近，但编写更快



```c++
class MedianFinder {
public:
	priority_queue<int> small;  //大顶堆，队头元素最大。（但是整体的值小）
	priority_queue<int, vector<int>, greater<int> > large; //小顶堆，队头元素最小。（但是整体的值大）
	/*
	它的模板声明带有三个参数，priority_queue<Type, Container, Functional>
	Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
	Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
	STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个
	参数缺省的话，优先队列就是大顶堆，队头元素最大。
	*/

	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		// 判断归属  最小堆large的所有元素都大于最大堆small
		if (large.empty() || num > large.top()) {
			large.push(num);
			// 平衡大小
			if (large.size() > small.size() + 1) {
				small.push(large.top());
				large.pop();
			}
		}
		else {
			small.push(num);
			// 平衡大小
			if (small.size() > large.size()) {
				large.push(small.top());
				small.pop();
			}
		}
	}

	double findMedian() {
		if (small.size() + large.size() & 1) {
			return large.top();
		}
		return 0.5 * (small.top() + large.top());
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

---

