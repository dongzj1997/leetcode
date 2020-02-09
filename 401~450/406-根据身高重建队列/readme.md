# 406-根据身高重建队列

```c++
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

别人[ivan_allen](https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-pai-xu-hou-/)已经写的够好了，我就直接贴在这里了

>[c++] 排序，然后插入。

>假设候选队列为 A，已经站好队的队列为 B.

>从 A 里挑身高最高的人 x 出来，插入到 B. 因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。比如 x 前面有 5 个人，那 x 就插入到队列 B 的第 5 个位置。


```c++

// 先排序
// [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]

// 再一个一个插入。
// [7,0]
// [7,0], [7,1]
// [7,0], [6,1], [7,1]
// [5,0], [7,0], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]


class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b) {
		if (a[0] != b[0])
			return a[0] > b[0];
		else {
			return a[1] < b[1];
		}
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> ans;
		for (auto t : people) {
			ans.insert(ans.begin() + t[1], t);
		}
		return ans;


	}
};
```

---



