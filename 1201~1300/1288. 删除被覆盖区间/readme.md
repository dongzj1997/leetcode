# 1288. 删除被覆盖区间

```c++
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 

提示：​​​​​​

1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-covered-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

典型的贪心算法， 先将输入按照起始时间从早到晚排序，如果起始时间相同，则按照结束时间从晚到早排序。

这样就保证了大区间永远在小区间前面。

遍历时候按照起始时间遍历，比较结束时间是否小于历史的最晚结束时间，执行响应的动作即可。

```c++
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a ,vector<int>& b){ if(a[0] != b[0]) return a[0] < b[0]; else return a[1] > b[1]; } );
        int len = intervals.size();
        int t = -1;
        int ans = len;
        for(int i=0;i<len;i++){
            if(intervals[i][1] > t){
                t = intervals[i][1] ;
            }
            else{
                ans--;
            }
        }
        return ans;
    }
};
```

---



