# 447-回旋镖的数量

```c++

```

---

我去，随便一写居然写对了，就是运行效率感人，超过22.09%

事实证明还是unorder_map好用

```c++
class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int ans = 0;
		int n = points.size(); //所有点的数量
		vector<unordered_map<int, int> > mp(n);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				auto a = points[i];
				auto b = points[j];

				int dist = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
				ans += mp[i][dist];
				mp[i][dist]++;

				ans += mp[j][dist];
				mp[j][dist]++;
			}
		}
		return ans*2;
	}
};

```

---



