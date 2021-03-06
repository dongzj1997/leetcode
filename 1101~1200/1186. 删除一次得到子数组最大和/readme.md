# 1186. 删除一次得到子数组最大和

```c++
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。

换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

请看示例：

示例 1：

输入：arr = [1,-2,0,3]
输出：4
解释：我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。
示例 2：

输入：arr = [1,-2,-2,3]
输出：3
解释：我们直接选出 [3]，这就是最大和。
示例 3：

输入：arr = [-1,-1,-1,-1]
输出：-1
解释：最后得到的子数组不能为空，所以我们不能选择 [-1] 并从中删去 -1 来得到 0。
     我们应该直接选择 [-1]，或者选择 [-1, -1] 再从中删去一个 -1。
 

提示：

1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray-sum-with-one-deletion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这种题和那几道股票问题，类似，关键是确定状态转移的方式，和确定子问题

详情见注释

```c++
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // a表示还没用删除机会时候的最大值，b表示删除机会已经用过的最大值
        int a = arr[0], b = 0xff3f3f3f;
        int ans = arr[0];
        int len =arr.size();
        for(int i=1;i<len;i++){
            b = max(a, b + arr[i]);  // 有两种情况可以生成b，一种是删除当前元素（就是上一次迭代的a），还有一种是从之前的b再加上当前元素生成而来，比较它们之间的最大值即可。
            a = max(arr[i], a+arr[i]);
            //同理a也有两种情况可以生成，直接取大值就好。

            ans = max({a,b,ans});
        }
        return ans;
    }
};
```

---

