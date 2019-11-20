# 241. 为运算表达式设计优先级

```c++
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析：递归划分

对每一个运算符，将其左右两边递归的执行diffWaysToCompute函数，然后将左右两边求得的值做组合，就是所有可能的值。

```c++
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		int flag = 0; //记录是否出现了运算符
		vector<int> ans;
		for (int i = 0; i < input.size(); ++i) {
			char c = input[i];
			if (c == '+' || c == '-' || c == '*') {
				flag = 1;
				vector<int> res1 = diffWaysToCompute(input.substr(0, i));//递归划分
				vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
				for (int r1 : res1) {//排列组合，计算结果
					for (int r2 : res2) {
						if (c == '+') {
							ans.push_back(r1 + r2);
						}
						else if (c == '-') {
							ans.push_back(r1 - r2);
						}
						else if (c == '*') {
							ans.push_back(r1 * r2);
						}
					}
				}
			}
		}
		if (flag == 0) {//纯数字，input中没符号
			ans.push_back(stoi(input));
		}
		return ans;
	}

};
```

---

