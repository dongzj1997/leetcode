# 373. 查找和最小的K对数字

```c++
给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。

示例 1:

输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:

输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:

输入: nums1 = [1,2], nums2 = [3], k = 3 
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题：使用优先级队列和位置指针快速求解

![img](./1.bmp)

首先，在遇到这种求前k个最大（最小）的问题时候，很自然的想到使用堆来减少时间复杂度。这里，使用优先级队列`priority_queue`来达到堆的效果。

第二，由于 nums1 和 nums2都是有序的，求前k个最小的则和类似一个指针从左到右不断滑动的过程，我们可以让数组1作为base，用另一个数组（长度和num1相等）来记录和从小到大过程中num1中每个元素 的另一半现在在num2数组中的位置。 每次循环找出是和最小的那一对，然后让那一对num2数组中的位置往前走一步，然后再次比较选出最小（使用优先级队列）。

---

有了这样的思路，我们就可以设计出合适的**数据结构**：

主要是队列q：

```c++
`priority_queue <pair<int,pair<int,int> >,vector<pair<int, pair<int, int> > >, cmp > q;`
```

看起来有点长,其实就是两个pair的嵌套`pair<int,pair<int,int> >`

外层pair第一个类型int是nums1 中的数(不是下标)， 第二个类型pair<int,int> 表示的是nums2中的数和对应的下标

之所以要这样存储，是因为比较函数`cmp`要作为参数传到priority_queue的构造函数中，要写出和具体数组无关的（不能在cmp函数中使用nums1和nums2），所以将具体的数值都存储进去。同时还要存储nums1中的数对应的nums2下标，便于插入下一个备选值。

整个算法运行的过程如下：

### 1. 优先队列的定义和初始化

初始化时，将nums1数组中每个数在nums2中的指针都置为0，加入到队列q中。

经过该步之后，队列的大小为nums1.size()，且已经根据从小到大排序好（最小的当然是nums1[0]和其在nums2中的指针0对应的数nums2[0]）

```c++
for (int i = 0; i < len1; i++) {
    pair<int, pair<int, int> > t(nums1[i], pair<int, int>(nums2[0] , 0));
    q.push(t);
}
```

### 2. 不断迭代，直到求出西前k个最小值

此后，每次迭代都固定的将队列头的最小值弹出，加入结果中，再将其在nums2中的指针加一后重新入队。（谁弹出，谁入队的模式类似于事件触发，可以避免浪费时间的遍历）。

比如第一个弹出的肯定是nums1[0]和其在nums2中的指针0对应的数nums2[0]，然后将指针+1，将nums1[0]和指针1及其对应的数nums2[0]入队列。

如果指针已经超出nums2的大小，不再入队列。

不断循环，直到求出前k个最小的数或者队列为空，结束，返回ans；

---

具体代码如下：

```c++
class Solution {
public:

	struct cmp {
		bool operator() (const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
			return a.first + a.second.first > b.first + b.second.first;
		}
	};

	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		int len1 = nums1.size();
		int len2 = nums2.size();
        if(len1 == 0 || len2 ==0){
            return vector<vector<int>>();
        }
		priority_queue <pair<int,pair<int,int> >,vector<pair<int, pair<int, int> > >, cmp > q;
		vector<vector<int>> ans;
		
		for (int i = 0; i < len1; i++) {
			pair<int, pair<int, int> > t(nums1[i], pair<int, int>(nums2[0] , 0));
			q.push(t);
		}
		for (int i = 0; i < k && !q.empty(); i++) {
			pair<int, pair<int, int> > t  = q.top();
			q.pop();
			vector<int> s = { t.first,t.second.first };
			ans.push_back(s);
			if (t.second.second < len2 - 1) {
				t.second.second++;
				t.second.first = nums2[t.second.second];
				q.push(t);
			}
		}
		return ans;
	}
};
```

### 复杂度分析

假设第一个数组的规模为`n`，需要求前k对数字,对于长度为`n`的priority_queue，或者队列头的时间复杂度为`O(1)`,插入一个元素时间复杂度为`O(logn)`。

总的时间复杂度由下列部分组成：

1. 初始建立priority_queue的时间复杂度为`O(n*logn)`

2. 获取前k个最小数对时间复杂度为`O(k*logn)`

总体时间复杂度为`O( (n+k)*logn)`

---

### 改进

通过上面的时间复杂度分析我们可以发现，时间复杂度和第一个数组的长度有关，和第二个数组长度关系不大，但是实际算法运行时对两个数组的大小没有特殊要求（数组1的指针指向数组2 和 数组2的指针指向数组1 都可以求解）。

所以可以选择数组长度较小的一个来充当数组1。

实际实现的时候主要是两点：

1. 如果数组1较大，对调1和2 `swap(nums1, nums2);`

2. 用一个flag表示存在对调，后期生成结果时也要注意将结果对调

```c++
    if (flag == 0) 
        ans.push_back({ t.first,t.second.first });
    else 
        ans.push_back({ t.second.first,t.first });
```

最后的总代码：用时8ms，超越100%

```C++
class Solution {
public:

	struct cmp {
		bool operator() (const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
			return a.first + a.second.first > b.first + b.second.first;
		}
	};
	
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 == 0 || len2 == 0) {
			return vector<vector<int>>();
		}
		int flag = 0;
        //如果nums1的长度大于nums2 则调换，保证nums1较短
		if (len1 > len2) {
			flag = 1;
			swap(nums1, nums2);
			swap(len1, len2);
		}

        //pair<int,pair<int,int> >，外层pair第一个类型int是nums1 中的数， 第二个类型pair<int,int> 表示的是nums2中的数和对应的下标
		priority_queue <pair<int,pair<int,int> >,vector<pair<int, pair<int, int> > >, cmp > q;
		vector<vector<int>> ans;
		
        //队列的初始化，将nums1中的所有数都入栈，每个数的初始指针设置为1
		for (int i = 0; i < len1; i++) {
			pair<int, pair<int, int> > t(nums1[i], pair<int, int>(nums2[0] , 0));
			q.push(t);
		}

        //取前k个最小的数，每次弹出最小的一个值，同时将其指针后移一位并入栈（如果指针没有到尾的话）
		for (int i = 0; i < k && !q.empty(); i++) {
			pair<int, pair<int, int> > t  = q.top();
			q.pop();
			vector<int> s();
			if (flag == 0) {
				ans.push_back({ t.first,t.second.first });
			}
			else {
				ans.push_back({ t.second.first,t.first });
			}
			
			if (t.second.second < len2 - 1) {
				t.second.second++;
				t.second.first = nums2[t.second.second];
				q.push(t);
			}
		}
		return ans;
	}
};
```

