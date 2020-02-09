# 498-对角线遍历

```c++
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

仔细观察，注意边界

```c++
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return {};
		int n = matrix[0].size();
		vector<int> ans;
		int a = 0, b = 0, maxlayer = m+n;

		for (int layer = 0; layer < maxlayer; layer++) {
			if (layer % 2 == 0) { //奇数层，从坐下 向 右上 遍历
				int x = (layer < m) ? layer : m - 1;
				int y = layer - x;
				while (x >= 0 && y < n)
				{
					ans.push_back(matrix[x][y]);
					x--;
					y++;
				}
			}
			else {
				int y = (layer < n) ? layer : n - 1;
				int x = layer - y;
				while (x < m && y >= 0) {
					ans.push_back(matrix[x][y]);
					x++;
					y--;
				}
			}
		}
		return ans;

	}
};
```

---



