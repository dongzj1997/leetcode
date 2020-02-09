# 473-火柴拼正方形

```c++
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

执行用时 :2016 ms, 在所有 C++ 提交中击败了5.02%的用户

累了~~~

```c++
class Solution {
public:
    int n, target;
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        n = nums.size();
        if (n < 4) 
            return false;
        for (auto t : nums) 
            sum += t;
        if (sum % 4 != 0) 
            return false;
        target = sum / 4;

        return dfs(0, 0, 0, 0, 0, nums);
    }

    bool dfs(int pos, int a, int b, int c, int d, vector<int>& nums) {

        if (a == target && b == target && c == target && d == target) return true;
        if (pos == n) return false;
        if (a + nums[pos] <= target && dfs(pos + 1, a + nums[pos], b, c, d, nums)) return true;
        if (b + nums[pos] <= target && dfs(pos + 1, a, b + nums[pos], c, d, nums)) return true;
        if (c + nums[pos] <= target && dfs(pos + 1, a, b, c + nums[pos], d, nums)) return true;
        if (d + nums[pos] <= target && dfs(pos + 1, a, b, c, d + nums[pos], nums)) return true;

        return false;
    }
};
```

---



