# 542. 01 矩阵

```c++
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

多源bfs 的思路比较容易想到，就不写了

下面写一个dp的方法。

由于最短可能是从四个方向得来的，再求某一点最短的时候无法保证其四个子问题都已经求解，所以使用两轮dp，取最小值。

```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++) { //自上而下，比较左边和上边
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] = INT_MAX - 1; //-1防止溢出
                    if (i > 0)     matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                    if (j > 0)     matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) { ////，自下而上，自右而左，比较右边和下边
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j]) {
                    if (i < m - 1)   matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
                    if (j < n - 1)   matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                }
            }
        }
        return matrix;
    }
};
```

---



