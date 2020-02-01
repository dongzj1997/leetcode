# 402-移掉K位数字

```c++
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

贪心算法，尽量消灭前面的逆序对中大的那个

如果消除完全部逆序对，k还有剩余，则从后往前删除字符串

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int n = num.size();
        int rest = n - k;
        for (char c : num) {
            while (k > 0 && ans.size() && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        ans = ans.substr(0, rest);
        
        //去除前面的0
        while (!ans.empty() && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        return ans.empty() ? "0" : ans;
    }
};
```

---



