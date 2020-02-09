# 440. 字典序的第K小数字

```c++
给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。

注意：1 ≤ k ≤ n ≤ 109。

示例 :

输入:
n: 13   k: 2

输出:
10

解释:
字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

刚开始有点难理解，多看看代码注释

```c++
class Solution {
public:
    int getCount(int prefix, int n) {
        int count = 0;
        int cur = prefix, next = prefix + 1; // 13 ，14
        while (cur <= n) {
            count += min(next, n + 1) - cur;
            cur *= 10;
            next *= 10; //将cur和next都乘以10 是为了统计这一层的节点个数，入第一层是（14-13 = 1）
                        // 第二层 是140-130 = 10 （也就是从130 ~139的10个，同理下一轮是1300 ~1399的100个）
            //那么为什么不直接count+= 1， 10， 100 呢
            // 这是为了实时查看这颗子树的上限（next），要不断的将上限和n+1左比较，取小值
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int p = 1; //p表示当前处理到第p个数字了
        int prefix = 1;  // 在找的数字本身
        while (p < k) {
            int count = getCount(prefix, n);  //活动以prefix为根节点的所有节点数（包括prefix本身）
            if (p + count > k) { //该子树下的所有节点大于k，表示要找的就在这个子树下
                prefix *= 10;
                p++; //进入子树的下一曾其实位置（入之前是13，进入位置为130，，p++ 是应为把13这个点算进去了）
            }
            else if (p + count <= k) {//表示要找的在这个兄弟子树上
                prefix++;
                p += count; // 将该子树的所有节点都加到已经处理的数字上来
            }
        }
        return prefix; //p ==  k的时候返回
    }
};
```

---



