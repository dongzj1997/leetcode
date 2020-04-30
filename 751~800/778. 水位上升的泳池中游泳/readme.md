# 778. 水位上升的泳池中游泳

```c++
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。

现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

示例 1:

输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
示例2:

输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输入: 16
解释:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
提示:

2 <= N <= 50.
grid[i][j] 位于区间 [0, ..., N*N - 1] 内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swim-in-rising-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单的dfs，注意到如果之前访问过该节点，但是现在的花费比之前小时，应该再进入该节点一次

dfs的效率还是不行，使用队列优先的bfs会比较快。

```c++
class Solution {
public:
    vector<vector<int>>vis;
    int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vis.resize(n, vector<int>(n, 0));
        vis[n-1][n-1] = 0x3f3f3f3f;
        dfs(0, 0, grid[0][0], grid);
        return vis[n - 1][n - 1];
    }
    void dfs(int x, int y, int mx, vector<vector<int>>& grid) {
        //ans 为访问到历史最小值
        if (x == grid.size() - 1 && x == y) {
            vis[x][y] = min(vis[x][y], mx);
            return;
        }
        vis[x][y] = mx;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            // vis[nx][ny] && vis[nx][ny] <= mx  访问过该节点并且 该节点的花费值小于当前
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size() || vis[nx][ny] && vis[nx][ny] <= mx) continue;
            dfs(nx, ny, max(mx, grid[nx][ny]), grid);
        }
    }
};
```

---



