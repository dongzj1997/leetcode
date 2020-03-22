# 743. 网络延迟时间

```c++
有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。
输入：times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
输出：2
 

注意:

N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。
```

---

## 解析

单元最短路径问题，有多种方法可以求解。

### Floyd算法

邻接表版（或为Bellman-Ford算法）

```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1,INT_MAX);
        dist[K] = 0; //k为起始节点
        dist[0] = 0;
        for(int i=0;i<N;i++){
            for(auto e:times){
                int st = e[0], ed = e[1], wi=e[2];
                if(dist[st] != INT_MAX){
                    dist[ed] = min(dist[ed], dist[st] + wi);
                }
            }
        }
        int ma = 0;
        for(int t :dist){
            ma = max(t,ma);
        }
        return ma == INT_MAX ? -1: ma;
    }
};
```

Bellman-Ford算法的时间复杂度是O(nm)，貌似比Dijkstra还高。事实上还可以进行优化，比如可以加一个bool变量check用来标记数组dis在本轮松弛中是否发生了变化，如果没有，就可以提前挑出循环。因为是“最多”达到n-1轮，实际情况下经常是早就已经达到最短，没法继续成功松弛了。

此外，还有SPFA算法（队列优化的Bellman-Ford），它的关键思想就在于：只有那些在前一遍松弛中改变了最短路估计值的结点，才可能引起它们邻接点最短路估计值发生改变。



邻接矩阵版

```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<long long>> graph(N+1,vector<long long>(N+1,INT_MAX));
        for(int i=1;i<=N;i++)    graph[i][i]=0;
        for(auto e:times)    graph[e[0]][e[1]]=e[2];
        
        for(int k=1;k<=N;k++)//k放在最外层
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        
        int ans=0;
        for(int i=1;i<=N;i++){
            if(graph[K][i]==INT_MAX) return -1;
            ans=max(ans,(int)graph[K][i]);
        }
        return ans;
    }
};
```

### DisjKstra算法

使用优先队列，适用于稀疏图：

想象将所有点分成visited和unvisited两个集合，优先队列记录的是和visited的点相连的边（注意纪录的是边）,队头是这些边中权值最小的一条边。

```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N+1,-1);
        dis[K]=0;
        using Pair=pair<int,int>;//first是距离，second是目标点
        priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
        pq.emplace(0,K);//起点先入队
        
        while(!pq.empty()){
            auto e=pq.top();pq.pop();//e为连接visited和unvisited的最小边
            if(e.first>dis[e.second]) continue;//如果e的权比K到e.second还大，就不可能缩短路径了
            for(int i=0;i<times.size();i++){
                if(times[i][0]==e.second){//遍历一遍所有以e.second为起点的边，做relax，并将relax之后的点入队
                    int v=times[i][1];
                    int w=e.first+times[i][2];
                    if(dis[v]==-1||dis[v]>w){
                        dis[v]=w;
                        pq.emplace(w,v);
                    }
                }
            }
            
        }
        
        int ans=0;
        for(int i=1;i<=N;i++){
            if(dis[i]==-1) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
```

不使用优先队列，适用于稠密图：

不使用优先队列，但引入visited向量记录是否使用过了（使用过的意思是被当做中间节点 ）
使用邻接矩阵表示邻接关系

```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<long long>> graph(N+1,vector<long long>(N+1,INT_MAX));
        for(int i=1;i<=N;i++)    graph[i][i]=0;
        for(auto e:times)    graph[e[0]][e[1]]=e[2];
        vector<bool> visited(N+1,false);    visited[K]=true;
        
        for(int i=1;i<N;i++){//进行一次表示，从K到j，经过一个点能不能缩短路径。一共进行N-1就可以。
            int min_id=0,min_dis=INT_MAX;//每次在unused的点中找到K最近的那个
            for(int j=1;j<=N;j++){
                if(visited[j]==false && graph[K][j]<min_dis){
                    min_dis=graph[K][j];
                    min_id=j;
                }
            }
            visited[min_id]=true;//把这个点标记为“使用过了”
            for(int j=1;j<=N;j++){//relax
                if(graph[K][min_id]+graph[min_id][j]<graph[K][j]){
                    graph[K][j]=graph[K][min_id]+graph[min_id][j];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            if(graph[K][i]==INT_MAX) return -1;
            ans=max(ans,(int)graph[K][i]);
        }
        return ans;
    }
};
```


```c++

```


---



