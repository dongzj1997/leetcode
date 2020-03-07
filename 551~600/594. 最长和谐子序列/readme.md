# 594. 最长和谐子序列

```c++
和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。

示例 1:

输入: [1,3,2,2,5,2,3,7]
输出: 5
原因: 最长的和谐数组是：[3,2,2,2,3].
说明: 输入的数组长度最大不超过20,000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-harmonious-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

本来想写`ans = max(it.second + mp[it.first+1],max(it.second + mp[it.first-1],ans););`的

突然发现没必要。

如果不使用map的方法的话，可以考虑排序

```c++
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        int ans = 0;
        for(auto it : mp){
            if(mp.count(it.first + 1)){
                 ans = max(it.second + mp[it.first+1],ans);
            }
        }
        
        return ans;
    }
};
```

---



