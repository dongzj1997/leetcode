# 995. K 连续位的最小翻转次数

```c++
在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0。

返回所需的 K 位翻转的次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。

 

示例 1：

输入：A = [0,1,0], K = 1
输出：2
解释：先翻转 A[0]，然后翻转 A[2]。
示例 2：

输入：A = [1,1,0], K = 2
输出：-1
解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
示例 3：

输入：A = [0,0,0,1,0,1,1,0], K = 3
输出：3
解释：
翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
 

提示：

1 <= A.length <= 30000
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

其实还是贪心算法，先要保证前面的数字处理完毕，

关键是当前面的处理过后，怎么快速处理对后面的影响，

第一种方法如下：使用一个队列记录处理过的节点，每次将超出影响范围的节点排除

```c++
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        queue<int> q;
        for (int i = 0; i <= n - K; i++) {
            while (!q.empty() && q.front() <= i - K) // 翻转的影响已经于A[i]无关，弹出
                q.pop();
            int l = q.size(); //前面翻转过几次
            if (A[i] == l % 2) {//判断i需不需要翻转
                ans++;
                q.push(i);
            }
        }

        //剩下不足k个无法翻转，只判断是否归位
        for (int i = n - K + 1; i < n; i++) {
            while (!q.empty() && q.front() <= i - K) q.pop();
            int l = q.size();
            if (A[i] == l % 2) return -1;
        }
        return ans;
    }
};

```
第二种方法更为巧妙，使用异或

当我们翻转一个子数组的时候，让我们称翻转子数组的下标集合为一个区间。我们将维护一个变量 flip，也就是覆盖当前位置的重叠区间数量。我们只关心 flip 对 2 取模之后的值。

我们翻转从 i 开始的一个区间，我们在位置 i+K 创建一个 “结束事件” 的提示，表明在那里要把翻转状态置反。

```java
class Solution {
    public int minKBitFlips(int[] A, int K) {
        int N = A.length;
        int[] hint = new int[N];
        int ans = 0, flip = 0;

        // 当我们翻转子数组形如 A[i], A[i+1], ..., A[i+K-1]
        // 我们可以在此位置置反翻转状态，并且在位置 i+K 设置一个提醒，告诉我们在那里也要置反翻转状态
        for (int i = 0; i < N; ++i) {
            flip ^= hint[i];
            if (A[i] == flip) {  // 我们是否必须翻转从此开始的子数组
                ans++;  // 翻转子数组 A[i] 至 A[i+K-1]
                if (i + K > N) return -1;  // 如果没办法翻转整个子数组了，那么就不可行
                flip ^= 1;
                if (i + K < N) hint[i + K] ^= 1;
            }
        }

        return ans;
    }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/solution/k-lian-xu-wei-de-zui-xiao-fan-zhuan-ci-shu-by-leet/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

---
