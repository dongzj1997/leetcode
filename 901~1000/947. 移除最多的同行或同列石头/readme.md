# 947. 移除最多的同行或同列石头

```c++

输出：0
 

提示：

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
```

---

题目有点绕，但实际是并查集

每次 move 操作都会移除一块所在行或者列上有其他石头存在的石头。

注意理解，一次移除，只移除一块石头

```c++
class Solution {
public:
    vector<int> parent;
    int cnt;
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size();
        cnt = len;
        parent = vector<int>(len);
        for (int i = 0; i < len; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < len; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    merge(i, j);
                    continue;
                }
            }
        }
        return len - cnt;
    }    
    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            parent[pa] = pb;
            cnt -= 1;
        }
    }
    int find(int a) {
        if (a != parent[a]) parent[a] = find(parent[a]);
        return parent[a];
    }
};
```

---
