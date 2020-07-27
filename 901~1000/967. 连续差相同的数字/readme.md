# 967. 连续差相同的数字

```c++
返回所有长度为 N 且满足其每两个连续位上的数字之间的差的绝对值为 K 的非负整数。

请注意，除了数字 0 本身之外，答案中的每个数字都不能有前导零。例如，01 因为有一个前导零，所以是无效的；但 0 是有效的。

你可以按任何顺序返回答案。

 

示例 1：

输入：N = 3, K = 7
输出：[181,292,707,818,929]
解释：注意，070 不是一个有效的数字，因为它有前导零。
示例 2：

输入：N = 2, K = 1
输出：[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

特别注意如果K为0的话，加减都一样，所以只走一个分支

用递归也可以很方面的做出来

```c++
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> vc;
        for (int i = 1; i < 10; i++) {
            vc.push_back(i);
        }
        if (N == 1) {
            return {0,1,2,3,4,5,6,7,8,9};
        }
        for (int i = 1; i < N; i++) {
            vector<int> t;
            for (int n : vc) {
                int tail = n % 10;
                if (tail + K < 10) {
                    t.push_back(n * 10 + (tail + K));
                }
                if (tail - K >= 0 && K != 0) {
                    t.push_back(n * 10 + (tail - K));
                }
            }
            swap(vc, t);
        }
        return vc;
    }
};
```

---
