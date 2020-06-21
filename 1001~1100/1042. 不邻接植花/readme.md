# 1042. 不邻接植花

```c++
有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。

paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。

另外，没有花园有 3 条以上的路径可以进入或者离开。

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

 

示例 1：

输入：N = 3, paths = [[1,2],[2,3],[3,1]]
输出：[1,2,3]
示例 2：

输入：N = 4, paths = [[1,2],[3,4]]
输出：[1,2,1,2]
示例 3：

输入：N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
输出：[1,2,3,4]
 

提示：

1 <= N <= 10000
0 <= paths.size <= 20000
不存在花园有 4 条或者更多路径可以进入或离开。
保证存在答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flower-planting-with-no-adjacent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

刚开始想复杂了，试着用回溯做，但是仔细看题，保证存在答案，另外，没有花园有 3 条以上的路径可以进入或者离开。

所以用贪心算法就可以完成，每次选一个点的第一个可用颜色就好。一次遍历所有点，就可以生成答案。

```c++
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N,0);
        //vector<map<int,int>> vmp(N);
        vector<set<int>> vst(N);
        for(auto & p:paths){
            vst[p[0] - 1].insert(p[1] - 1);
            vst[p[1] - 1].insert(p[0] - 1);
        }
        for(int i=0;i<N;i++){
            bool usd[5] = {0};
            auto & st = vst[i];
            for(int e:st ){
                usd[ans[e]] = true;
            }
            for(int j=1;j<5;j++){
                if(!usd[j]){
                    ans[i] = j;
                    break;
                }
                    
            }
        }
        return ans;
    }
};
```

---
