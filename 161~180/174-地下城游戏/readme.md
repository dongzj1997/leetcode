# 地下城游戏

```c++
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

 

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。

-2 (K)	-3	    3
-5	    -10	    1
10	     30	-5 (P)
 

说明:

骑士的健康点数没有上限。

任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dungeon-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题：采用倒着的动态规划算法

大体思想是：从最后的终点出发，不断的向做左上使用动态规划。

**动态规划矩阵中存储的是从该节点开始至少需要多少生命值可以到达终点**

动态规划时，从当前点的右边、下边两者之中选择一个耗费生命较小的（此时该两点耗费多少生命可以达到终点已知），也就是二者之中的最优选择，然后算上**本身这个格子所需要的血量**，就是该节点最小的耗费生命值了。

最后返回dp[0][0],表示从原点开始需要多少血量到达终点。

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        
        dp[m][n-1] = 1; dp[m-1][n] = 1;
        for(int i = m-1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);//dp逆推
            }
        }
        return dp[0][0];
    }
};
```

---

## 思考，为什么不能正向推，只能逆向推？

首先附上我首先尝试过的正向dp的代码：(使用dp矩阵存储最小需求，使用hp矩阵存储血量)

```C++
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {

		int m = dungeon.size();       //m行
		int n = dungeon[0].size();    //n列

		vector<vector<int>> dp(m, vector<int>(n, 0)); //存储到达这一点的还是没死的最少需求
		vector<vector<int>> hp(m, vector<int>(n, 0)); //存储到达这一点的血量

		hp[0][0] = dungeon[0][0];
		if (hp[0][0] >= 0) {
			dp[0][0] = 0;
		}
		else {
			dp[0][0] = -dungeon[0][0];
			hp[0][0] = 0;
		}



		if (m == 1 && n == 1) {  //只有单个元素
			return dp[0][0] + 1;
		}

		if (n == 1) { //只有一列
			for (int i = 1; i < m; i++) {  //初始化第一列
				hp[i][0] = hp[i - 1][0] + dungeon[i][0];
				if (hp[i][0] >= 0) {  //血量健康，不需要加需求
					dp[i][0] = dp[i - 1][0];
				}
				else {       //血量小于0，还需要加需求
					dp[i][0] = dp[i - 1][0] - hp[i][0];
					hp[i][0] = 0;
				}
			}

			return dp[m - 1][0] + 1;
		}

		if (m == 1) {  //只有一行
			for (int i = 1; i < n; i++) {  //初始化第一行
				hp[0][i] = hp[0][i - 1] + dungeon[0][i];
				if (hp[0][i] >= 0) {
					dp[0][i] = dp[0][i - 1];
				}
				else { //血量小于0，还需要加需求
					dp[0][i] = dp[0][i - 1] - hp[0][i];
					hp[0][i] = 0;
				}
			}

			return dp[0][n - 1] + 1;
		}


		for (int i = 1; i < m; i++) {  //初始化第一列
			hp[i][0] = hp[i - 1][0] + dungeon[i][0];
			if (hp[i][0] >= 0) {  //血量健康，不需要加需求
				dp[i][0] = dp[i-1][0];
			}
			else {       //血量小于0，还需要加需求
				dp[i][0] = dp[i - 1][0] - hp[i][0];
				hp[i][0] = 0;
			}
			
		}



		for (int i = 1; i < n; i++) {  //初始化第一行
			hp[0][i] = hp[0][i - 1] + dungeon[0][i];
			if (hp[0][i] >= 0) {
				dp[0][i] = dp[0][i - 1];
			}
			else { //血量小于0，还需要加需求
				dp[0][i] = dp[0][i - 1] - hp[0][i];
				hp[0][i] = 0;
			}
		}


		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				int hp1 = hp[i - 1][j] + dungeon[i][j];
				int hp2 = hp[i][j-1] + dungeon[i][j];

				int req1 = hp1 >= 0 ? dp[i - 1][j] : dp[i - 1][j] - hp1;
				int req2 = hp2 >= 0 ? dp[i][j - 1] : dp[i][j - 1] - hp2;

				if (req1 < req2) {
					dp[i][j] = req1;
					hp[i][j] = hp1 >=0 ? hp1 :0;
				}
				else if (req1 > req2) {
					dp[i][j] = req2;
					hp[i][j] = hp2 >= 0 ? hp2 : 0;
				}
				else {
					dp[i][j] = req1;
					hp[i][j] = max(hp1, hp2);
					hp[i][j] = hp[i][j] >= 0 ? hp[i][j] : 0;
				}

			}
		}
		return dp[m - 1][n - 1] +1;
	}
};
```

很遗憾，这个代码只能通过 41/45 个用例，显然是存在Bug的。但是问题在哪呢？

仔细思考，可以发现，动态规划所要求的状态转移方程其实并不成立，也就是说 知道dp[i][j-1]和dp[i-1][j] 并不能推出dp[i][j]。
比如用例：[[1,-3,3],[0,-2,0],[-3,-3,-3]]

dp[i][j]和 dp[i][j-1] 、 dp[i-1][j] 的关系并没有那么强。

但是知道 dp[i][j+1] 和 dp[i+1][j]，，再结合当前需要的血量，就可以确定当前的dp[i][j]。

所以说，不要着急写代码，老老实实的分析一下dp的状态转移方程再动手。
