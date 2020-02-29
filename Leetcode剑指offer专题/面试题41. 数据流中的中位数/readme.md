# 面试题41. 数据流中的中位数

```c++
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：

最多会对 addNum、findMedia进行 50000 次调用。
注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

两个堆，一个大顶堆存储较小的那一半元素，一个小顶堆存较大的那些元素。

可以接受小顶堆的元素数量比大顶堆多一个。

最后总数如果是奇数，则返回大顶堆元素即可，如果是偶数，去两堆顶元素求平均

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



