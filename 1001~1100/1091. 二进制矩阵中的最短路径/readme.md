# 1091. 二进制矩阵中的最短路径

```c++
在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。

一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：

相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
C_1 位于 (0, 0)（即，值为 grid[0][0]）
C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

 

示例 1：

输入：[[0,1],[1,0]]

输出：2

示例 2：

输入：[[0,0,0],[1,1,0],[1,1,0]]

输出：4

 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-in-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

标准bfs，用队列实现，

```c++
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        //int n = grid[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        if(grid[0][0]==1)return -1;
        queue<pair<int,int>>q;
        grid[0][0]=2; //访问过
        q.push({0,0});

        int step = 1;
        while(!q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==m-1 && y==m-1) return step;
                for(int j=0;j<8;j++){
                    int x1=x+dir[j][0];
                    int y1=y+dir[j][1];
                    if(x1<0||y1<0||x1>=m||y1>=m || grid[x1][y1])continue;
                    grid[x1][y1]=2;
                    q.push({x1,y1});
                }
            }
            step++;
        }
        return -1;
    }
};
```

---

