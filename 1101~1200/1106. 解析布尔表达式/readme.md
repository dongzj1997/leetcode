# 1106. 解析布尔表达式

```c++
给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 

示例 1：

输入：expression = "!(f)"
输出：true
示例 2：

输入：expression = "|(f,t)"
输出：true
示例 3：

输入：expression = "&(t,f)"
输出：false
示例 4：

输入：expression = "|(&(t,f,t),!(t))"
输出：false
 

提示：

1 <= expression.length <= 20000
expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
expression 是以上述形式给出的有效表达式，表示一个布尔值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parsing-a-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用递归下降语法分析

使用c++ 17中的string_view比直接使用string要快一点，不过快的也不多。

使用类似计算器的 双栈 数据结构 也可以很快的解题。

```c++
class Solution {
public:
	bool parseBoolExpr(string expression) {
		string_view s(expression.data());
		return parseBoolExpr(s);
	}
	bool parseBoolExpr(string_view expression) {
		if (expression.size() == 1) {
			if (expression[0] == 'f') return false;
			else return true;
		}

		if (expression[0] == '&') {
			return parseAND(expression.substr(2, expression.size() - 3));
		}
		else if (expression[0] == '|') {
			return parseOR(expression.substr(2, expression.size() - 3));
		}
		else if (expression[0] == '!') {
			return parseNOT(expression.substr(2, expression.size() - 3));
		}
        return false;
	}

	bool parseOR(string_view exp) {
		vector<string_view> tokens = split(exp, ',');;
		for (auto& s : tokens) {
			if (parseBoolExpr(s) == true) {
				return true;
			}
		}
		return false;
		
		
	}
	bool parseAND(string_view exp) {
		vector<string_view> tokens = split(exp, ',');;
		for (auto& s : tokens) {
			if (parseBoolExpr(s) != true) {
				return false;
			}
		}
		return true;
	}
	bool parseNOT(string_view exp) {
		return !parseBoolExpr(exp);
	}

	vector<string_view> split(string_view s, char delim = ' ') {
		vector<string_view> ans;
		int cnt = 0;
		int beg = 0;
		int len = s.size();
		for (int i = 0; i < len;i++) {
			char c = s[i];
			if (c == '(') cnt++;
			else if (c == ')') cnt--;
			else if (c == delim && cnt == 0) {
				ans.push_back(s.substr(beg, i - beg));
				beg = i + 1;
			}
		}
		ans.push_back(s.substr(beg));
		return ans;
	}
	
};
```

---

