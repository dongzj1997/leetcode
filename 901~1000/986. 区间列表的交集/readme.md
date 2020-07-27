# 986. 区间列表的交集

```c++
给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。

返回这两个区间列表的交集。

（形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）

 

示例：



输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

提示：

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interval-list-intersections
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

各种区间问题无非是贪心，并且一般都是找结束时间早的，将其剔除或者加到结果中来。

前提是要记得排序。

```c++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i <lenA && j <lenB){
            int l=max(A[i][0],B[j][0]);
            int r=min(A[i][1],B[j][1]);
            if(l <= r) ans.push_back({l,r});
            //这里用到贪心的思想，将结束时间早的剔除
            if(A[i][1] < B[j][1]) i++;
            else j++;        
        }
        return ans;
    }
};
```

---
