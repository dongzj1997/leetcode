# 面试题38. 字符串的排列

```c++
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个侧例真的弱，使用set都能通过

执行用时 :96 ms, 在所有 C++ 提交中击败了55.01%的用户

```c++
class Solution {
public:
	vector<string> ans;
	int len = 0;
	unordered_set<string> st;
	vector<string> permutation(string s) {
		sort(s.begin(), s.end());
		len = s.size();
		helper(s, 0);
		return ans;
	}

	void helper(string& s, int pos) {
		if (pos == len) {
			if (st.count(s) == 0) {
				st.insert(s);
				ans.push_back(s);
			}
				
			return;
		}
			
		helper(s, pos + 1);
		for (int i = pos + 1; i < len; i++) {
			if (s[pos] == s[i])
				continue;
			swap(s[pos], s[i]);
			helper(s, pos + 1);
			swap(s[pos], s[i]);
		}
	}
};
```

---

再补一个不使用set的版本,44 ms

```c++
class Solution {
public:
	vector<int> temp2;
	//vector<vector<int>> res2;
	vector<string> permutation(string s ) {
		sort(s.begin(), s.end());
		int n = s.size();
		string temp;
		vector<string> res;
		vector<bool> visited(n, false);
		DFS(s, temp, res, 0, visited);
		return res;
	}

	void DFS(string& s, string& temp, vector<string> &res, int cursize, vector<bool>& visited) {
		if (cursize == s.size()) {
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < s.size(); i++) {
			if (!visited[i]) {
				if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])  //保证了相同的排列只有倒叙访问一种情况，如1，1，1，2  ，前三个111访问顺序只能是3，2，1  （如果前一个相同元素访问过，直接continue）
					continue;                                            // 如果改为 ！visited[i - 1] ，则访问顺序只能是1，2，3 (前一个相同元素还没有访问，则直接continue)
				temp.push_back(s[i]);//记录值                              //任何一次continue都会导致最终的元素不够，注定无结果，可以直接改为return；
				temp2.push_back(i);//记录访问顺序
				visited[i] = true;
				DFS(s, temp, res, cursize + 1, visited);

				temp.pop_back();
				temp2.pop_back();
				visited[i] = false;
			}
		}
	}
};

```
