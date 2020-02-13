# 面试题12. 矩阵中的路径

```c++
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    int row = 0, col = 0;
    int x[4] = { -1,0,0,1 };
    int y[4] = { 0,-1,1,0 };
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        if (row == 0)
            return word.size() == 0;
        col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 1, board, word )) 
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs( int i, int j, int index, vector<vector<char>>& board, string& word) {
        if (index == word.size()) 
            return true;
        char t = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            int new_x = i + x[k];
            int new_y = j + y[k];
            if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && word[index] == board[new_x][new_y]) {
                if (dfs( new_x, new_y, index + 1,board, word)) 
                    return true;
            }
        }
        board[i][j] = t;
        return false;
    }
};

```

---



