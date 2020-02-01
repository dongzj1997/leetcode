# 399. 除法求值

```c++
给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :
给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：

equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-division
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

解题区大神写的并查集方法，学习了

主要注意的是marge函数和ask函数

1. 在`merge（a，b）`时，将`b`的父节点`bb`挂在`a`的父节点`aa`下面，然后跟新`bb`的值`val[bb] = val[a] * 1.0 / val[b] * v`;

2. 查找`a，b`时，返回`return val[b] * 1.0 / val[a];`

3. 在`getFather`时记得及时更新节点关系和节点值 `val[x] = val[x] * val[fa[x]];`

```c++
void merge(const string& a, const string& b, double v) {
    init(a); init(b);
    string aa = getFather(a), bb = getFather(b);
    fa[bb] = aa;
    val[bb] = val[a] * 1.0 / val[b] * v;
}
double ask(const string& a, const string& b) {
    if (!exist(a) || !exist(b)) return -1;
    string aa = getFather(a), bb = getFather(b);
    if (aa != bb) return -1;
    return val[b] * 1.0 / val[a];
}
```

```c++

class Solution {
private:
	class unionSet {
	private:
		unordered_map<string, string> fa;
		unordered_map<string, double> val;

		bool exist(const string& x) { return fa.find(x) != fa.end(); }

		void init(const string& x) {
			if (exist(x)) return;
			val[x] = 1;
			fa[x] = x;
		}

		string getFather(const string& x) {
			if (fa[x] == x) return x;
			else {
				string f = getFather(fa[x]);
				val[x] = val[x] * val[fa[x]];
				return fa[x] = f;
			}
		}
	public:
		void merge(const string& a, const string& b, double v) {
			init(a); init(b);
			string aa = getFather(a), bb = getFather(b);
			fa[bb] = aa;
			val[bb] = val[a] * 1.0 / val[b] * v;
		}
		double ask(const string& a, const string& b) {
			if (!exist(a) || !exist(b)) return -1;
			string aa = getFather(a), bb = getFather(b);
			if (aa != bb) return -1;
			return val[b] * 1.0 / val[a];
		}
	};
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unionSet u;
		for (int i = 0; i < equations.size(); i++) {
			u.merge(equations[i][0], equations[i][1], values[i]);
		}
		vector<double> ans;
		for (int i = 0; i < queries.size(); i++) {
			ans.push_back(u.ask(queries[i][0], queries[i][1]));
		}
		return ans;
	}
};

```

---

此外，还可以用图的方法来做，使用dfs或者bfs均可

