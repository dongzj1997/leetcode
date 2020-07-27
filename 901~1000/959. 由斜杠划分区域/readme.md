# 959. 由斜杠划分区域

```c++
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。

 

示例 1：

输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：

示例 2：

输入：
[
  " /",
  "  "
]
输出：1
解释：2x2 网格如下：

示例 3：

输入：
[
  "\\/",
  "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：

示例 4：

输入：
[
  "/\\",
  "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：

示例 5：

输入：
[
  "//",
  "/ "
]
输出：3
解释：2x2 网格如下：

 

提示：

1 <= grid.length == grid[0].length <= 30
grid[i][j] 是 '/'、'\'、或 ' '。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

根据评论区[@EiletXie]的代码修改

很好的练习并查集的一道题、关键是将N*N*4的图映射到一维向量上去。

```c++
class Solution {
public:
    class unionset {
    public:
        vector<int> parent;

        unionset(int size) {
            parent = vector<int>(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }
        int find(int i) {
            int t = i;
            while (i != parent[i])
                i = parent[i];
            parent[t] = i;
            return i;
        }
        void merge(int a, int b) { //b作为长辈
            int fa = find(a);
            int fb = find(b);
            parent[fa] = fb;
        }
    };

        //----
        //|\/|
        //|/\|
        //----   从最上开始，顺时针编号为0123
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        auto us = unionset(N * N * 4);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int start = 4 * (i * N + j); 
                switch (grid[i][j]) {
                case ' ':
                    us.merge(start, start + 1);
                    us.merge(start, start + 2);
                    us.merge(start, start + 3);
                    break;
                case '/':
                    us.merge(start, start + 3);
                    us.merge(start + 1, start + 2);
                    break;
                case '\\':
                    us.merge(start, start + 1);
                    us.merge(start + 2, start + 3);
                    break;
                }

                if (i > 0) { //说明非第一行，最上边的块和上一行最下面的块相连
                    us.merge(start, start - 4 * N + 2);
                }
                if (j > 0) { //非第一列，最左边的块和左边的右块相连接
                    us.merge(start + 3, start - 3);
                }
            }
        }
        for (int i = 0; i < N * N * 4; i++) {
            if (i == us.parent[i])
                ans++;
        }
        return ans;

    }
};
```

---
