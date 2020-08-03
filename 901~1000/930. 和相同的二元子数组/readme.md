# 930. 和相同的二元子数组

```c++
在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。

 

示例：

输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

提示：

A.length <= 30000
0 <= S <= A.length
A[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-subarrays-with-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

方法1，前缀和，基本题

```c++
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int a:A){
            sum += a;
            ans += mp[sum - S];
            mp[sum]++;
        }
        return ans;
    }
};
```

由于只有0，或者1，并且数组长度最大为30000，所以使用数组来模拟map更快

```c++
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int mp[30000] = {0};
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int a:A){
            sum += a;
            if(sum - S >= 0)
                ans += mp[sum - S];
            mp[sum]++;
        }
        return ans;
    }
};
```

---

方法2：滑动窗口

```c++
//想了一下，滑动窗口还不太好做，这之前的一道题比较相似
//当前值小于S时则表示右指针向前，小于S时表示左指针需要向前
//等于S的时候，还要判断左右指针处各自还有多少个0，再计算结果，比较复杂
```
