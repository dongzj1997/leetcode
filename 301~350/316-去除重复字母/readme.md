# 316. 去除重复字母

```c++
给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

示例 1:

输入: "bcabc"
输出: "abc"
示例 2:

输入: "cbacdcbc"
输出: "acdb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++

class Solution {
public:
	string removeDuplicateLetters(string s) {
		string ans = "";
		int count[26] = {0};
		bool added[26] = { 0 };
		bool instack[26] = { 0 };

		stack<char> Stack;
		Stack.push('a' - 1);
		for (char c : s) {
			count[c-'a']++;
		}

		for (char c : s) {
			count[c - 'a']--;
			if (added[c - 'a']) {
				continue;
			}
			if (instack[c - 'a']) {
				//count[c - 'a']--;
				continue;
			}

			while (Stack.top() >= c) {
				//尝试将栈顶较大的元素弹出
				if (count[Stack.top() - 'a'] >= 1 || Stack.top() == c) {
					instack[Stack.top() - 'a'] = 0;
					Stack.pop();
					

				}
				else {
					//栈顶元素是最后一个，将栈顶和之前的都加入结果

					string t = "";
					while (Stack.top() != ('a' - 1)) {
						t += Stack.top();
						added[Stack.top()-'a'] = 1;

						Stack.pop();
					}
					reverse(t.begin(), t.end());
					ans += t;
				}
			}

			Stack.push(c);
			instack[c - 'a'] = 1;
			
		}
		string t = "";
		while (Stack.top() != ('a' - 1)) {
			if (added[Stack.top() - 'a']) {
				Stack.pop();
				continue;
			}
			t += Stack.top();
			Stack.pop();

		}
		reverse(t.begin(), t.end());
		ans += t;

		return ans;
	}
};
```

---

坐了半天的车，回家有点迷糊，提交了4此才AC，代码也写得很乱，修修补补的地方很多，通过了赶紧睡~~~

简单解析：

遇到一个新字符 如果比栈顶小 并且栈顶元素在新字符后面还有和栈顶一样的 就把栈顶的字符抛弃（计数-1），直到新字符是栈中最大的字符为止。

如果遇到要弹出的元素是最后一个，否则说明这个字符位置已经确定，将该元素和之前的元素都加入到最终结果中，并且将相关标志位置1。

需要注意的点：

1. 先将字符出现的次数计数count

2. 如果该字符已经在栈中，则直接跳过该字符

3. 确定后的字符也直接跳过
