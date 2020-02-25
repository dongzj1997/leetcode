# 面试题13. 机器人的运动范围

```c++
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 1：

输入：m = 3, n = 1, k = 0
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单题

```c++
class Solution {
public:
	
	int movingCount(int m, int n, int k) {
		queue< pair<int,int> > q;
		q.push({ 0,0 });
		int ans = 1;
		vector< vector<bool> > exist(m, vector<bool>(n,false));
		int ori[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
		exist[0][0] = true;

		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int new_x = t.first + ori[i][0];
				int new_y = t.second + ori[i][1];
				if (canEnter(new_x, new_y, exist,m, n, k)) {
					ans++;
					exist[new_x][new_y] = true;
					q.push({ new_x ,new_y });
				}
			}
		}

		return ans;
	}

	bool canEnter(int x, int y, vector< vector<bool> >& exist, int m, int n, int k) {
		if (x < 0 || x >= m || y < 0 || y >= n || exist[x][y])
			return false;
		int val = 0;
		while (x > 0 || y > 0) {
			val += x % 10;
			x /= 10;
			val += y % 10;
			y /= 10;
		}
		return val <= k;
	}
};
```

---



