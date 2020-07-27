# 910. 最小差值 II

```c++
给定一个整数数组 A，对于每个整数 A[i]，我们可以选择 x = -K 或是 x = K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

 

示例 1：

输入：A = [1], K = 0
输出：0
解释：B = [1]
示例 2：

输入：A = [0,10], K = 2
输出：6
解释：B = [2,8]
示例 3：

输入：A = [1,3,6], K = 3
输出：3
解释：B = [4,6,3]
 

提示：

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {
        int len = A.size();
		sort(A.begin(), A.end());
        //以i为中点，之前的数全部加K，之后的数全部减K，然后找最小差值
		int ans = A[len-1]-A[0];
		for (int i = 1; i < A.size(); i++) {
			int minValue = min(A[0] + K, A[i] - K);//最小值
			int maxValue = max(A[len - 1] - K, A[i - 1] + K);//最大值

			ans = min(maxValue - minValue, ans);
		}
		return ans;
	}
};
```

---
