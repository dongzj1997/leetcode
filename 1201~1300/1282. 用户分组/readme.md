# 1282. 用户分组

```c++
有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。

你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。

 

示例 1：

输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]
解释： 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
示例 2：

输入：groupSizes = [2,1,3,3,3,2]
输出：[[1],[0,5],[2,3,4]]
 

提示：

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用map记录每个组有那些下标，后续遍历map，按大小分组即可。

```c++
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int> > mp;
        int len = groupSizes.size();
        for(int i=0;i < len;i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto c:mp){
            int sz = c.first;
            int idx = 0;
            vector<int>& t = c.second;
            while(idx != t.size()){
                vector<int> a;
                for(int j=0;j<sz;j++){
                    a.push_back(t[idx+j]);
                }
                idx += sz;
                ans.push_back(a);
            }
        }
        return ans;
    }
};
```

---



