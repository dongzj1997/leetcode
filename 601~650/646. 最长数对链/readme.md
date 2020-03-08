# 646. 最长数对链

```c++
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

示例 :

输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-pair-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

贪心

```c++
class Solution {
public:
    static bool cmp(const vector<int> & a,const vector<int> & b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans=1,len=pairs.size();
        
        int right=pairs[0][1];
        for(int i=1;i<len;i++){
            if(pairs[i][0]>right){
                right=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};
```

---



