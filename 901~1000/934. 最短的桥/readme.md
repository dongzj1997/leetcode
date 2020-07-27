# 934. 最短的桥

```c++
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）

 

示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
 

提示：

1 <= A.length = A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-bridge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这种题读完题就知道要先标记，然后广度优先搜索，就差直接给你写到题目中了。

代码冗长，实在不想写了，但是又想凑一个900题，所以代码来源于[这里](https://leetcode-cn.com/problems/shortest-bridge/solution/dfszhao-dao-bfszhao-zui-xiao-ju-chi-by-muyids/)

找了一个相对还Clean的代码。

```c++
class Solution {
public:
    int dirR[4] = { -1, 0, 1, 0 };
    int dirC[4] = { 0, 1, 0, -1 };
    queue<pair<int, int>> q;

    int shortestBridge(vector<vector<int>>& A) {
        // dfs 查找两个岛,标记第一个岛为2
        for (int i = 0; i < A.size() * A[0].size(); i++) {
            if (A[i / A[0].size()][i % A[0].size()] == 1) {
                dfs(A, i / A[0].size(), i % A[0].size());
                break;
            }
        }

        int step = 0;
        // bfs里面的岛的所有点，向外扩展，记录层数，当遇到第一个岛的时候，返回层数
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; i++) {
                auto f = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int r = dirR[d] + f.first;
                    int c = dirC[d] + f.second;
                    if (r < 0 || r >= A.size() || c < 0 || c >= A[0].size()) continue;
                    if (A[r][c] == 2) continue;
                    if (A[r][c] == 1) return step;
                    A[r][c] = 2;
                    q.push({ r, c });
                }
            }
            step++;
        }

        return step;
    }

    void dfs(vector<vector<int>>& A, int i, int j) {
        q.push({ i, j });
        A[i][j] = 2;
        for (int d = 0; d < 4; d++) {
            int r = dirR[d] + i;
            int c = dirC[d] + j;
            if (r < 0 || r >= A.size() || c < 0 || c >= A[0].size()) continue;
            if (A[r][c] == 0 || A[r][c] == 2) continue;
            dfs(A, r, c);
        }
    }
};

```

---
