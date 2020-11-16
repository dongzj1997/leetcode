# 20. 有效的括号

```c++
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
//其实可以增加一个判断：如果栈的深度大于字符串长度的1/2，就返回false。因为当出现这种情况的时候，即使后面的全部匹配，栈也不会为空。

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) {
			return true;
		 }
		

		string t(s.length()+1, ' ');
		int index = 0;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{') {
				t[++index] = c;
			}
			else if (c == ')') {
				if (t[index] == '(')
					index--;
				else {
					return false;
				}
			}
			else if (c == ']') {
				if (t[index] == '[')
					index--;
				else {
					return false;
				}
			}
			else if (c == '}') {
				if (t[index] == '{')
					index--;
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		if (index == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	Solution s = Solution();
	string input = "(((((";
	//vector<string> ans = s.letterCombinations(input);
	cout << s.isValid(input) << endl;

	return 0;
}
```

---
