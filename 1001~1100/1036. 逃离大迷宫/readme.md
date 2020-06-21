# 1036. 逃离大迷宫

```c++
在一个 10^6 x 10^6 的网格中，每个网格块的坐标为 (x, y)，其中 0 <= x, y < 10^6。

我们从源方格 source 开始出发，意图赶往目标方格 target。每次移动，我们都可以走到网格中在四个方向上相邻的方格，只要该方格不在给出的封锁列表 blocked 上。

只有在可以通过一系列的移动到达目标方格时才返回 true。否则，返回 false。

 

示例 1：

输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
输出：false
解释：
从源方格无法到达目标方格，因为我们无法在网格中移动。
示例 2：

输入：blocked = [], source = [0,0], target = [999999,999999]
输出：true
解释：
因为没有方格被封锁，所以一定可以到达目标方格。
 

提示：

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= blocked[i][j] < 10^6
source.length == target.length == 2
0 <= source[i][j], target[i][j] < 10^6
source != target

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/escape-a-large-maze
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

就是一个带停止条件的bfs，一堆强制类型转换给我整吐了，int还是有点小，只有10位10进制数，21亿左右。

```c++
class Solution {
public:
	//                           blocked = [[0, 1], [1, 0]], source = [0, 0], target = [0, 2]
	//                           10^6 x 10^6 网格
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		int border = 1e6;
		int blclen = blocked.size();
		int dir[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0,1} };
		queue<pair<int, int>> q1, q2;
		q1.push({ source[0], source[1] });
		q2.push({ target[0], target[1] });
		unordered_set< long> st1, st2;
		st1.insert( (long)source[0] * border + source[1] );
		st2.insert( (long)target[0] * border + target[1] );

		unordered_set< long> blc;
		for (auto& b : blocked) {
			blc.insert((long)b[0] * border + b[1]);
		}
        if(blc.count((long)source[0] * border + source[1])) return false;
        if(blc.count((long)target[0] * border + target[1])) return false;

		while (q1.size() && q2.size()) {
			int minsize = min(q1.size(), q2.size());
			if (minsize >= blclen * 2)
				return true;
			if (q1.size() <= q2.size()) {//从起点开始找
				int len = q1.size();
				while (len--) {
					auto t = q1.front();
					long tt = (long)t.first * border + t.second;
					q1.pop();
					if (st2.count(tt)) return true;
					//if (st1.count(t)) continue;
					for (int i = 0; i < 4; i++) {
						pair<int, int> newt = { t.first + dir[i][0], t.second + dir[i][1] };
						if (newt.first < 0 || newt.first >= border || newt.second < 0 || newt.second >= border)
							continue;

						long ntt = (long)newt.first * border + newt.second;
						if (blc.count(ntt)) continue;
						if (!st1.count(ntt)) {
							st1.insert(ntt);
							q1.push(newt);
						}
					}
				}
			}
			else { //从终点开始找
				int len = q2.size();
				while (len--) {
					auto t = q2.front();
					long tt = (long)t.first * border + t.second;
					q2.pop();
					if (st1.count(tt)) return true;
					//if (st1.count(t)) continue;
					for (int i = 0; i < 4; i++) {
						pair<int, int> newt = { t.first + dir[i][0], t.second + dir[i][1] };
						if (newt.first < 0 || newt.first >= border || newt.second < 0 || newt.second >= border)
							continue;
						long ntt = (long)newt.first * border + newt.second;
						if (blc.count(ntt)) continue;
						if (!st2.count(ntt)) {
							st2.insert(ntt);
							q2.push(newt);
						}
					}
				}

			}
		}

		return false;
	}
};
```

---
