# 378. 有序矩阵中第K小的元素

```c++
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明:
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1，多路归并，优先级队列

84 ms, 在所有 C++ 提交中击败了14.59%的用户

```c++
class Solution {
public:
	struct cmp {
		bool operator() (const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
			return a.first  > b.first ;
		}
	};

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		priority_queue< pair<int, pair<int, int> > ,vector<pair<int, pair<int, int> > >,cmp  >q;
		for (int i = 0; i < m; i++) {
			q.push(pair<int, pair<int, int> >(matrix[i][0], pair<int, int>(i,0) ));
		}
		int ans = 0;
		for (int i = 0; i < k && !q.empty(); i++) {
			auto t = q.top();
			ans = t.first;
			q.pop();
			//cout << ans << endl;

			if (t.second.second < n - 1) {
				t.second.second++;
				t.first = matrix[t.second.first][t.second.second];
				q.push(t);
			}
		}

		return ans;
	}
};
```

---

## 解法2 ，二分查找

来自[@JackSu](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/er-fen-chao-ji-jian-dan-by-jacksu1024/)


思路非常简单：

1.找出二维矩阵中最小的数left，最大的数right，那么第k小的数必定在left~right之间

2.mid=(left+right) / 2；在二维矩阵中寻找小于等于mid的元素个数count

3.若这个count小于k，表明第k小的数在右半部分且不包含mid，即left=mid+1, right=right，又保证了第k小的数在left~right之间

4.若这个count大于k，表明第k小的数在左半部分且可能包含mid，即left=left, right=mid，又保证了第k小的数在left~right之间

5.因为每次循环中都保证了第k小的数在left~right之间，当left==right时，第k小的数即被找出，等于right

注意：这里的left mid right是数值，不是索引位置。

```java
    public int kthSmallest(int[][] matrix, int k) {
        int row = matrix.length;
        int col = matrix[0].length;
        int left = matrix[0][0];
        int right = matrix[row - 1][col - 1];
        while (left < right) {
            // 每次循环都保证第K小的数在start~end之间，当start==end，第k小的数就是start
            int mid = (left + right) / 2;
            // 找二维矩阵中<=mid的元素总个数
            int count = findNotBiggerThanMid(matrix, mid, row, col);
            if (count < k) {
                // 第k小的数在右半部分，且不包含mid
                left = mid + 1;
            } else {
                // 第k小的数在左半部分，可能包含mid
                right = mid;
            }
        }
        return right;
    }

    private int findNotBiggerThanMid(int[][] matrix, int mid, int row, int col) {
        // 以列为单位找，找到每一列最后一个<=mid的数即知道每一列有多少个数<=mid
        int i = row - 1;
        int j = 0;
        int count = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] <= mid) {
                // 第j列有i+1个元素<=mid
                count += i + 1;
                j++;
            } else {
                // 第j列目前的数大于mid，需要继续在当前列往上找
                i--;
            }
        }
        return count;
    }


```
