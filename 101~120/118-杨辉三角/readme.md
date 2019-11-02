# 118. 杨辉三角

```c++
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		for (int i = 0; i < numRows; i++) {
			vector<int> tmp(i + 1, 0);
			tmp[0] = 1;
			tmp[i] = 1;
			for (int j = 1; j < i; j++) {
				tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans.push_back(tmp);
		}
		return ans;
	}
};
```

---

没有什么难度，注意边界即可。
