# 面试题29. 顺时针打印矩阵

```c++
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector <int> res;
		if (matrix.empty())
			return res;
		int top = 0, button = matrix.size() - 1; //上下边
		int left = 0, right = matrix[0].size() - 1; //左右边
		while (1) {
			for (int i = left; i <= right; i++) 
				res.push_back(matrix[top][i]);//从左往右
			if (++top > button) break; //若超出边界，退出
			for (int i = top; i <= button; i++) 
				res.push_back(matrix[i][right]);//从上往下
			if (--right < left) break;
			for (int i = right; i >= left; i--) 
				res.push_back(matrix[button][i]);//从右往左
			if (--button < top) break;
			for (int i = button; i >= top; i--) 
				res.push_back(matrix[i][left]);//从下往上
			if (++left > right) break;
		}
		return res;
	}
};
```

---



