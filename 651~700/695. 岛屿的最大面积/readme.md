# 695. 岛屿的最大面积

```c++
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单的递归

```c++
class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    ans = max(ans, helper(grid, i, j));
            }
        }
        
        return ans;
    }
    
    int helper(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= m) return 0;
        if(y < 0 || y >= n) return 0;
        if(grid[x][y] != 1) return 0;
        
        grid[x][y] = 2;
        
        int a = helper(grid, x-1,y);
        int b = helper(grid, x+1,y);
        int c = helper(grid, x,y-1);
        int d = helper(grid, x,y+1);
        
        return 1+a+b+c+d;
        
    }
};
```

---



