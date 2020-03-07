# 528. 按权重随机选择

```c++
给定一个正整数数组 w ，其中 w[i] 代表位置 i 的权重，请写一个函数 pickIndex ，它可以随机地获取位置 i，选取位置 i 的概率与 w[i] 成正比。

说明:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex 将被调用不超过 10000 次
示例1:

输入: 
["Solution","pickIndex"]
[[[1]],[]]
输出: [null,0]
示例2:

输入: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
输出: [null,0,1,1,1,0]
输入语法说明：

输入是两个列表：调用成员函数名和调用的参数。Solution 的构造函数有一个参数，即数组 w。pickIndex 没有参数。输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-with-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

按照蓄水池抽样的思维，时间复杂度略久。

评论区的方法更加恰当：从前往后从小到大，给每个i分配一个大小等于其权重的范围区间，总范围加起等于sum(w)。 在sum(w)内随机取一个整数，二分查找它在第几个区间，返回所在区间的下标。

比如 [4, 2]，变成 [4, 6]；



```c++

class Solution {
public:
    vector<int> t;
    Solution(vector<int>& w) {
        t = w;
    }
    
    int pickIndex() {
        int len = t.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<len;i++){
            sum +=t[i];
            int g =  rand() % sum;
            if(g < t[i])
                ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```

---



