# 763. 划分字母区间

```c++
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1:

输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先用一个数组将每个字母的end位置记录下来，然后贪心算法搞定

```c++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> start(26, -1);
        int end[26] = {0};
        for(int i=0;i<S.size();i++){
            char c = S[i];
            if(start[c-'a'] == -1){
                start[c-'a'] = i;
            }
            end[c-'a'] = i;
        }
        vector<int> ans;
        int left = 0, right = 0;
        for(int i=0;i<S.size();i++){
            right = max(right, end[S[i] - 'a']);
            if(i == right) {
                ans.push_back(right - left + 1);
                left = right + 1;
            }
                
        }
        return ans;
    }
};
```

---



