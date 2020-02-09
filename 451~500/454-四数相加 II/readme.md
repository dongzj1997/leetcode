# 454-四数相加 II

```c++
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

写完看一眼评论区果然最高赞是这种方法。

所见略同

```c++
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int ans = 0;
		unordered_map<int,int> sum1;
		int len1 = A.size(), len2 = B.size(), len3 = C.size(), len4 = D.size();
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				sum1[A[i] + B[j]]++;
			}
		}
		for (int i = 0; i < len3; i++) {
			for (int j = 0; j < len4; j++) {
				ans += sum1[-(C[i] + D[j])];
			}
		}
		return ans;

	}
};
```

---



