# 1162. 地图分析

```c++
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。

我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。

如果我们的地图上只有陆地或者海洋，请返回 -1。

 

示例 1：



输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释： 
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
示例 2：



输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释： 
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

看了一圈很少有用dp做的，自己写一个

```c++
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    continue;
                else{
                    grid[i][j] = 0x3f3f3f3f;
                    if(i > 0)
                        grid[i][j] = min(grid[i][j], grid[i-1][j] + 1);
                    if(j > 0)
                        grid[i][j] = min(grid[i][j], grid[i][j-1] + 1);
                }
                
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 1)
                    continue;
                else{
                    //grid[i][j] = 0x3f3f3f3f;
                    if(i < m-1)
                        grid[i][j] = min(grid[i][j], grid[i+1][j] + 1);
                    if(j < n-1)
                        grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
                    ans = max(ans, grid[i][j]);
                }
                
            }
        }
        return ans >= 0x3f3f3f3f ? -1:ans-1;
    }
};
```

---



