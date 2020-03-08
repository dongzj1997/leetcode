# 650. 只有两个键的键盘

```c++
最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：

Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
Paste (粘贴) : 你可以粘贴你上一次复制的字符。
给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。

示例 1:

输入: 3
输出: 3
解释:
最初, 我们只有一个字符 'A'。
第 1 步, 我们使用 Copy All 操作。
第 2 步, 我们使用 Paste 操作来获得 'AA'。
第 3 步, 我们使用 Paste 操作来获得 'AAA'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

dp一波，注意将复制次数的初始值设为2，然后代价是`dp[i] + tm`刚好包含了复制+粘贴的操作，以后每次加一都是执行的粘贴操作。

```c++
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,n+1);
        dp[1] = 0;
        for(int i=1;i<=n;i++){
            int sp = dp[i];
            int tm = 2;
            while(i*tm <=n){
                dp[i*tm] = min(dp[i*tm], dp[i] + tm );
                tm++;
            }
        }
        return dp[n];
    }
};
```

---



