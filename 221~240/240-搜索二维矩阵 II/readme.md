# 240. 搜索二维矩阵 II

```c++
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        if(len == 0) 
            return false;
        int i = 0, j = matrix[0].size()-1;
        while(i < matrix.size() && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target) {
                ++ i;
            }
            else {
                -- j;
            }
        }
        return false;
    }
};
```

---

左下角的元素有如下特性：

1. 这一行中最小的元素

2. 这一列中最大的元素

我们西选坐下角的元素为起点，就相当于站在了一个十字路口，根据值的大小可以做以下动作：

1. 若当前元素等于目标，则找到，返回真

2. 若左下角元素大于目标，则目标不可能存在于当前元素所在行，问题规模可以减小为在去掉最后一行的子矩阵中寻找目标（相当于切掉下面的部分）

3. 若左下角元素小于目标，则目标不可能存在于当前元素所在列，（切掉左边部分）

---

同理，选择右上角也可以。




---
此外，还可以使用二分法，但时间复杂度劣于此法