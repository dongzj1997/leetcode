# 1584. 连接所有点的最小费用

```c++
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

最小生成树模板题，可以用prim算法或者Kruskal算法。

prim算法（点集扩充）（N^2版本）：

```c++
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<bool> vis(n);

        // 从当前已经收录点集出发的最短边的长度。
        vector<int> min_dist(n, 0x3f3f3f3f);

        min_dist[0] = 0;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            int gmin = 0x3f3f3f3f;
            for (int j = 0; j < n; ++j) {
                // 选出距离顶点最近的，但是还没访问过的一个点u。
                if (!vis[j] && min_dist[j] <= gmin) {
                    gmin = min_dist[j];
                    u = j;
                }
            }
            ans += gmin;
            vis[u] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) { // 如果这个点还没有被加入到点集中，则尝试看看能不能以更短的方式访问
                    int new_dist = abs(points[j][0] - points[u][0]) + abs(points[j][1] - points[u][1]);
                    min_dist[j] = min(min_dist[j], new_dist);
                }
        }
        return ans;
    }
};
```

---

Kruskal算法(森林中的树进行合并，用到并查集):

```c++
class Solution {
public:
    vector<int> fa;
    vector<pair<int, pair<int,int>>> nums;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        for (int i = 0; i < len; i++) fa.push_back(i);

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                nums.push_back({ abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) , {i,j} });
            }
        }
        sort(nums.begin(), nums.end());
        int cnt = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i].second.first, b = nums[i].second.second;
            int dis = nums[i].first;
            int na = find(a), nb = find(b);
            if (na != nb) {
                cnt++;
                res += dis;
                fa[na] = nb;
            }
            if (cnt == len - 1)
                break;
        }
        return res;
    }
    int find(int n) {
        if (fa[n] == n) return n;
        fa[n] = find(fa[n]);
        return fa[n];
    }
};
```