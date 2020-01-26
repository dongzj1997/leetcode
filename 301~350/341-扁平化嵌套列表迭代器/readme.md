# 341. 扁平化嵌套列表迭代器

```c++
给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的项或者为一个整数，或者是另一个列表。

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用递归的方法

```c++
class NestedIterator {
public:
	vector<int> v;
	int index = 0;
	NestedIterator(vector<NestedInteger>& nestedList) {
		dfs(nestedList);
	}

	void dfs(vector<NestedInteger>& nestedList) {
		for (auto t : nestedList) {
			if (t.isInteger()) {
				v.push_back(t.getInteger());
			}
			else {
				dfs(t.getList());
			}
		}
	}

	int next() {
		auto ans = v[index];
		index++;
		return ans;
	}

	bool hasNext() {
		return !(index == v.size());
	}
};
```

---



