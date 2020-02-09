# 433. 最小基因变化

```c++
一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。

例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。

与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。

现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。

注意:

起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
所有的目标基因序列必须是合法的。
假定起始基因序列与目标基因序列是不一样的。
示例 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

返回值: 1
示例 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

返回值: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

懒得编写测试用例一次提交居然直接通过了！

其实就是广度优先搜索，（甚至可以用数字运算来判断是否相等）
（其实也就十六位的数字而已）

```c++
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		char replace[4] = { 'T','A','C','G' };
		int round = 0;
		queue<string> q;
		q.push(start);

		unordered_set<string> mp;
		for (string s : bank) {
			mp.insert(s);
		}

		while (!q.empty()) {
			int len = q.size();
			round++;
			for (int i = 0; i < len; i++) {
				auto s = q.front();
				q.pop();
				for (int j = 0; j < 8; j++) {
					auto t = s;
					for (int k = 0; k < 4; k++) {
						t[j] = replace[k];
						if (mp.find(t) != mp.end()) {
							mp.erase(t);
							if (t == end)
								return round;
							else {
								q.push(t);
							}
						}
					}
				}
			}

		}
		return -1;
	}
};
```

---



