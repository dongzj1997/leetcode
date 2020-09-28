# 1590. 使数组和能被 P 整除

```c++
给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。

 

示例 1：

输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
示例 2：

输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
示例 3：

输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
示例  4：

输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
示例 5：

输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-sum-divisible-by-p
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

看到解题都是用的先扫描一遍，计算总和，然后求出去需要去掉的那一段取余值是多少，利用前缀和 and 字典求出结果。

这里提供一种不同的做法，只不过时间和空间复杂度不是最优值。

用到一个数据结构`map<int, vector<int>> mp;`，map的key表示余数，value表示出现的位置，从前到后。

1. 先顺序遍历一遍，然后存余数出现的位置。

2. 然后从后到前扫描一遍，每次扫描到一个位置的时候，把这个我位置前缀和对应的余数删掉。

3. 计算出后缀和的余数sum，然后得出需要余数为need 的前缀和，从mp中查找有没有。

4. 如果有的话，计算最小值即可。

```c++
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int len = nums.size();
        map<int, vector<int>> mp;
        int sum = 0;
        int ans = INT_MAX;
        vector<int> sss(len, 0);
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            sum %= p;
            if (sum == 0) {
                ans = min(ans, len - i - 1);
            }
            sss[i] = sum;
            mp[sum].push_back(i);
        }
        if (sum == 0) return 0;
        sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum += nums[i];
            sum %= p;
            if (sum == 0) {
                ans = min(ans, i);
            }
            int tsum = sss[i];
            auto& tv = mp[tsum];
            tv.pop_back();
            if (tv.size() == 0)
                mp.erase(tsum);

            int need = p - sum;
            if (mp.find(need) != mp.end()) {
                ans = min(ans, i - mp[need].back() - 1);
            }

        }
        if (sum == 0) return 0;
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
```

---
