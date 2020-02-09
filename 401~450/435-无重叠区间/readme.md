# 435-无重叠区间

```c++
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

贪心算法（好像和之前第一次学算法的时候问 活动中心最多能安排多少个节目那个问题有点相似）

本题目是删除多少个区间使之不重叠，那么当我每次不得不删除时，删除那个长的肯定比删除短的要划算。

活动中心最多排多少个节目那个问题，就是能保留多少个区间，使他们互不重复，

正确做法是：按照终点排序，在不冲突的情况下优先上结束的早的，这样可能容纳的节目更多。

```c++

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0]; //从小到大
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if(intervals.size() == 0) 
            return 0;
        int ans = 0;
        
        //按照起始位置进行排序。
        sort(intervals.begin(), intervals.end(), cmp);
        
        int end = intervals[0][1];//最远的结束位置。
        for(int i = 1; i != intervals.size(); i++)
        {
            //发生重叠
            if(intervals[i][0] < end){ 
                ans++; //删掉end较大的那个
                end = min(intervals[i][1], end);
            }
            //没有发生重叠 更新end
            else{
                end = intervals[i][1];        
            }
        }
        return ans;
    }
};
```

---



