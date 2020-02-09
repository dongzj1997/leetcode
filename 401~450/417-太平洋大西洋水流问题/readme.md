# 417-太平洋大西洋水流问题

```c++
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

逆向dfs或者bfs

```c++
class Solution {
public:
    int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int> > res;
        if (matrix.empty()) 
            return res;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int> > status(R, vector<int>(C, 0));
        queue<pair<int, int> > q;
        for (int i = 0; i < R; ++i) {
            q.push({ i, 0 });
            status[i][0] |= 1;
            q.push({ i, C - 1 });
            status[i][C - 1] |= 2;
        }
        for (int i = 0; i < C; ++i) {
            q.push({ 0, i });
            status[0][i] |= 1;
            q.push({ R - 1, i });
            status[R - 1][i] |= 2;
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int r = p.first + dirs[i][0];
                int c = p.second + dirs[i][1];
                if (valid(r, c, R, C) && matrix[r][c] >= matrix[p.first][p.second]) {
                    if (status[r][c] != status[p.first][p.second]) {
                        status[r][c] |= status[p.first][p.second];
                        q.push({ r, c });
                    }
                }
            }
        }


        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (status[i][j] == 3) {
                    res.push_back({ i, j });
                }
            }
        }
        return res;
    }
};

```

---



