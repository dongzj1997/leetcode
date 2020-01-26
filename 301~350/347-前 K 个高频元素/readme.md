# 347. 前 K 个高频元素

```c++
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题1 （hashmap + 排序）

开始写的第一版，复杂度为o(logn)，C++ 提交中击败了38.46%的用户。

总体思路就是先将原始数组转为map，然后对map 中的value进行排序，最后选出其中前k大的。

```c++

class Solution {
public:
	
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int t : nums) {
			if (m.count(t) == 0) {
				m[t] = 1;
			}
			else {
				m[t]++;
			}
		}

		vector<pair<int, int>> vec(m.begin(), m.end());

		sort(vec.begin(), vec.end(),cmp);

		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(vec[i].first);
		}
		return ans;
	}


	//static很关键
	static bool cmp(const pair<int, int>& a, const  pair<int, int>& b) {
		return a.second > b.second;
	}

};
```

这里写的时候遇到了一个问题，在写sort的cmp函数时，如果在类中定义的函数体为`bool cmp(int a,int b)`，vs会出现`error C3867: “&”: 绑定成员函数表达式上的非法操作`，的错误。

这是因为：类的成员函数默认带有一个this指针参数，那么它作为泛函的参数其实就不匹配了，因为泛函中的Func类型并没有this指针，就出现了错误。（实际上编译器认为 cmp函数是有3个参数的，但是sort中不会提供相应的参数）

静态成员函数的地址可用普通函数指针储存，而普通成员函数地址需要用类成员函数指针来储存，因为普通成员函数要执行时我们必须要确定他是属于哪个类对象才能执行，而类的static函数是不属于这个类的，他是在编译器编译时期就已经确定的，普通成员函数是在有了类对象之后才能执行。

解决办法主要有：

1. 把`cmp()`函数声明为静态（static）的，这样就不带有this指针；副作用时静态的函数又不能访问非静态的成员

2. 将这个`cmp()`函数提到类外面定义。

3. 使用友元函数

---

## 解法2（hashmap + 最小堆）

题目最终需要返回的是前 k 个频率最大的元素，可以想到借助堆这种数据结构，对于频率k之后的元素不用再去处理，进一步优化时间复杂度。

需要维护一个大小为k的最小堆（堆顶的元素最小），算法的时间复杂度大约为O(nlogk)

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        // 使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
        HashMap<Integer,Integer> map = new HashMap();
        for(int num : nums){
            if (map.containsKey(num)) {
               map.put(num, map.get(num) + 1);
             } else {
                map.put(num, 1);
             }
        }
        // 遍历map，用最小堆保存频率最大的k个元素
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return map.get(a) - map.get(b);
            }
        });
        for (Integer key : map.keySet()) {
            if (pq.size() < k) {
                pq.add(key);
            } else if (map.get(key) > map.get(pq.peek())) {
                pq.remove();
                pq.add(key);
            }
        }
        // 取出最小堆中的元素
        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            res.add(pq.remove());
        }
        return res;
    }
}

作者：MisterBooo
链接：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```

## 解法3 （hashmap + 桶排序算法）

对于这种值有上限和下限，，且均匀分布，差别不大的情况，使用桶排序可以节约大量的时间

```c++
    //统计次数
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i)
    {
        ++m[nums.at(i)];
    }

    //使用二维数组  统计次数作为第一维的下标（如果统计次数有相同，则将值追加到桶中）
    vector<vector<int>> buckets(nums.size() + 1);

    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        buckets.at(iter->second).push_back(iter->first);
    }

    //将buckets中前k个高频元素放入res中
    vector<int> res(k);
    int count = 0;
    for (int i = buckets.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < buckets.at(i).size(); ++j)
        {
            res.at(count) = buckets.at(i).at(j);
            ++count;
            if (count == k)
                return res;
        }
    }


```

作者：eric-345
链接：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/c-shi-xian-by-eric-345/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。