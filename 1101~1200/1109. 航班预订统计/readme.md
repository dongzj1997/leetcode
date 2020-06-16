# 1109. 航班预订统计

```c++
这里有 n 个航班，它们分别从 1 到 n 进行编号。

我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。

请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。

 

示例：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
 

提示：

1 <= bookings.length <= 20000
1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
1 <= bookings[i][2] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/corporate-flight-bookings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

O(n)的复杂度居然只击败了5%，大家都是什么神仙

```c++
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto vc :bookings){
            mp1[vc[0]]+= vc[2];
            mp2[vc[1]]+= vc[2];
        }
        vector<int> ans(n,0);
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += mp1[i];
            ans[i-1] = sum;
            sum -= mp2[i];
        }
        return ans;
    }
};
```

---

