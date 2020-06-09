# 1289. 下降路径最小和  II

```c++
给你一个整数方阵 arr ，定义「非零偏移下降路径」为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。

请你返回非零偏移下降路径数字和的最小值。

 

示例 1：

输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
输出：13
解释：
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
 

提示：

1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-falling-path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

基本上很容易想到，思路直来直去的dp（感觉是中等难度），一个dp数组，记录对应位置上的累计最小值即可。直接在网页编辑，一次AC。

代码的复杂度是O(n^3)级别，如果不嫌麻烦的话，起始每次只记录上面一行的两个最小值即可（还包括对应下标）。

那么时间复杂度会进一步降低到O(n^2)，， 空间复杂度也会降低到O(1).

但是这个题的规模有点小O(n^3) 的代码看着更加优美统一。

```c++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<int> dp = arr[0];
        for(int i=1;i<m;i++){
            vector<int> t(n);
            for(int j=0;j<n;j++){
                
                int mx = INT_MAX;
                for(int k=0;k<n;k++){
                    if(j == k) continue;
                    mx = min(dp[k], mx);
                }
                t[j] = mx + arr[i][j];
            }
            swap(dp,t);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(dp[i], ans);
        }
        return ans;
    }
};
```

---



