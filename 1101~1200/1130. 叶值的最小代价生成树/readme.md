# 1130. 叶值的最小代价生成树

```c++
给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：

每个节点都有 0 个或是 2 个子节点。
数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。

 

示例：

输入：arr = [6,2,4]
输出：32
解释：
有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

提示：

2 <= arr.length <= 40
1 <= arr[i] <= 15
答案保证是一个 32 位带符号整数，即小于 2^31。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

比较典型的一道三维dp（第一维度是区间长度），

盯着边界条件盯了好久，点个sta，以后再看看

```c++
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int len = arr.size();

        int mx[41][41] = {0};
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0x3f3f3f3f));
        for (int i = 0; i <= len; i++) dp[i][i] = 0;

        for(int i=0;i<len;i++){
            int t = 0;
            for(int j=i;j<len; j++){
                t = max(t, arr[j]);
                mx[i][j] = t;
            }
        }

        for (int i = 1; i < len; i++) { // 长度
            for (int j = 0; j < len - i; j++) { // 起始点
                for (int k = j; k < j + i; k++) { // 中间点
                    dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + mx[j][k] * mx[k+1][j+i]);
                }
            }
        }
        return dp[0][len-1];
    }
};
```

---

