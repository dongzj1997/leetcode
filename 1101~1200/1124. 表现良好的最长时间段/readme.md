# 1124. 表现良好的最长时间段

```c++
给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。

 

示例 1：

输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。
 

提示：

1 <= hours.length <= 10000
0 <= hours[i] <= 16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-well-performing-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---
字典+前缀和，既然是找「劳累的天数」是严格 **大于**「不劳累的天数」，就直接找`mp.count(sum -1)`即可。

如果是**等于**，那么就是普通的前缀和，找`mp.count(sum)`

此外，还有单调栈的解法，更加巧妙。

```c++
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();

        unordered_map<int , int >mp;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<len;i++){
            sum += (hours[i] > 8 ? 1 : -1);
            if( sum > 0) ans = i + 1;
            else{
                if(mp.count(sum) == 0) mp[sum] = i;
                if(mp.count(sum -1))
                    ans = max(ans, i - mp[sum-1]);
            }
        }
        return ans;
    }
};
```

---

