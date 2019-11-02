# 120. 三角形最小路径和

```c++
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 0) {
			return 0;
		}
		vector<int> ans(n, INT_MAX);
		ans[0] = triangle[0][0];
		for (int i = 1; i < n; i++) {
			ans[i] = ans[i - 1] + triangle[i][i];
			for (int j = i-1; j>0; j--) {
				ans[j] = min(ans[j], ans[j - 1]) + triangle[i][j];
			}
			ans[0] = ans[0] + triangle[i][0];
		}
		auto minPosition = min_element(ans.begin(), ans.end());
		return *minPosition;
	}
};
```

---

常规的动态规划，和上一题的杨辉三角差不多。同样的是对j倒着遍历可以防止需要的值被修改，对每一行的最后一个和第一个特别考虑。

还有一点要注意，求最小值时，由于vector属于STL中的模板类，是一种容器，而它里面又没有定义相关的函数求最大值。因此要麻烦很多。而操作vector的核心就是采用迭代器。使用迭代器和algorithm库中的max_element函数来求得vector中的最大值，

这里的auto其实在运行的时候就被自动替换为了`vector<int>::iterator`类型。

```c++
int main(){
    vector<int> a = { 2,4,6,7,1,0,8,9,6,3,2 };
    auto maxPosition = max_element(a.begin(), a.end());
    cout << *maxPosition << " at the postion of " << maxPosition - a.begin() <<endl;
    //cout << a[maxPosition - a.begin()] << " at the postion of " << distance(a.begin(), maxPosition) << endl;
    system("pause");
    return 0;
}
```

!!! 对于迭代器，可以理解为下表，两个迭代器可以相减求得下标之差，也可以直接对迭代器解引用 `*`，来获得对应的值。

---

执行用时 :4 ms, 在所有 cpp 提交中击败了97.58%的用户

内存消耗 :9.6 MB, 在所有 cpp 提交中击败了94.34%的用户
