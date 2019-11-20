# 224-基本计算器

```c++
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析：巧用运算符优先级表和栈实现计算器

在解析常规的算术表达式时，最麻烦的问题是每个运算符优先级不同，有时还带有括号，比如在解析`3 + 4 * 2`的时候，读取完`3+4`并不能马上计算结果，还要查看 4 后面的运算符优先级，如果大于前一个算符的优先级，就要先计算优先级较高的`4*2`，然后计算`3 + 8`。（为了存储`3 +` 这个等待解析的表达式，我们使用两个栈：`运算符栈`和`运算数栈`。利用栈天然的后入先出特性）

其实，仔细想一想，解析过程是有章可循的，在解析过程种，一共只会遇到两种情况：

1. 如果在一个运算符后面遇到优先级更高的运算符，如`3 + 4 * 2`，那么我们就先不进行运算，先将之前的表达式存起来（可以利用栈存储`3 +`），然后等后面高优先级的计算完毕后再来计算,（返回8，计算 3 + 8）。

2. 如果一个运算符后面遇到优先级和他相同（如`3 + 4 - 2`），或者优先级还不如它的运算符（如`3 * 4 + 2`）.那么我们可以放心的先把已经解析的表达式求出来，然后再做下一步的解析。

运算符的优先级是确定的，我们可以生成如下一张算符优先级表：

```c++
char table[9][9] = {   //算符优先级表 
//           +   -   *   /   ^   !   (   )   #    // 当前运算符
    /* + */ '>','>','<','<','<','<','<','>','>',
    /* - */ '>','>','<','<','<','<','<','>','>',
    /* * */ '>','>','>','>','<','<','<','>','>',
    /* / */ '>','>','>','>','<','<','<','>','>',
    /* ^ */ '>','>','>','>','>','<','<','>','>',
    /* ! */ '>','>','>','>','>','>',' ','>','>',
    /* ( */ '<','<','<','<','<','<','<','=',' ',
    /* ) */ ' ',' ',' ',' ',' ',' ',' ',' ',' ',
    /* # */ '<','<','<','<','<','<','<',' ','='
    // 栈顶运算符
};
```

其中，为了确保解析结果后所有的运算符都能出栈，我们人为的将表达式前后都添加一个`#`号，表示开始和结束，它的优先级最小。算符优先级表的横轴表示当前运算符，纵轴表示栈顶运算符，比如`table[0][2]='<'`，表示之前存入栈种的运算符 `+` 小于当前解析到的运算符`*`。有个这个表，我们就可以方便的对表达式进行解析。

### 解析前的准备，数据结构和预处理

解析过程种要用到两个栈，用来存储已经解析到，但是还没有进行运算的符号和数字：

```c++
stack<char> OPTR;//操作符栈
stack<int> OPND;//操作数栈 
```

除此之外，还要在表达式前后都插入优先级最低的`#`，保证表达式结束时之前任意优先级的运算符都可以进行解析。

```c++
OPTR.push('#');
s += '#';
```

### 读取数字

数字都是以字符串的形式给我们的，有长有短。 我们采用不断入栈-出栈-更新-入栈的方法。
先假设数字长度为1，将字符转为数字后入栈，如果接下来又解析到一个数字，那么将之前入栈的数字弹出，执行
`int t = OPND.top();   t = t * 10 - '0' + c ;`后再次入栈（先-‘0’后加c是防止int溢出）。

那么，如何在解析过程中知道当前解析的是数的首个字符还是后续字符呢？

我们使用一个变量flag来表示，具体实现如下：

```c++
int flag = 0;
for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ')
        continue;
    if (isdigit(c)) {
        if (flag) {   //连续数字
            int t = OPND.top();
            OPND.pop();
            t = t * 10 + c - '0';
            OPND.push(t);
        }
        else {
            OPND.push(c - '0');
            flag = 1;
        }
    }
}
```

### 解析运算符

首先，当读取到一个运算符的时候，表示数字已经读取完了，别忘了将flag置位`flag = 0;`。

解析运算符的时候我们要做如下操作：

第一步，先从栈顶获取之前的一个运算符（如果是刚开始解析，那么栈顶元素是`#`）

第二步，根据运算符表将前一个运算符和当前运算符作比较，此时一共会出现3中结果：

1. 栈顶运算符优先级更低，则继续进栈（如 3 +3 * ，栈顶的运算符为+，当前的运算符为 *）

2. 栈顶运算符优先级和当前相同，这种情况只会发生在左右括号，两个`#`之间，说明括号内的内容已经解析完毕，将这一对括号弹出即可。

3. 此时栈顶元素的优先级高于当前元素，此时不再进行解析，而是**处理已经入栈的值**。（那么，当前循环指针已经读到了新的运算符，我们使用`i--;`，来将指针强制拉回到解析这个符号之前，就当这个符号没有见到过）

```c++
flag = 0;
char opt = OPTR.top();
switch (orderBetween(opt, c)) { //使用orderBetween获取两个运算符之间的关系
    case '<'://栈顶运算符优先级更低，则继续进栈
        OPTR.push(c); break;
    case '=':
        OPTR.pop(); break;
    case '>': {
        i--;  //此时栈顶元素的优先级高于当前元素，此时不再进行解析，而是处理已经入栈的值(a的光标拉回到解析这个符号之前)
        OPTR.pop();

        //// 处理已经入栈的值
    }
```

### 处理已经入栈的值

对于一元和二元运算符，处理的过程是不同的，这里只用到二元运算符，情况比较简单，三步搞定：

1. 将操作数栈的两个元素出栈

2. 根据栈顶的运算符做相应的运算（记得弹出）

3. 将新的值入栈

代码如下：

```c++
char opt = OPTR.top();
OPTR.pop();

int num1 = OPND.top();
OPND.pop();
int num2 = OPND.top();
OPND.pop();

num1 = evaluate2(num1, opt, num2);
OPND.push(num1);

int evaluate2(int a, char opt, int b) {  //处理二元运算符
    switch (opt) {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/': {
            if (a == 0) {
                printf("ERROE zero cannot be div");
                return 0;
            }
            return b / a;
        }
        case '^':
            return (int)pow(b, a);
    }
    return -1;
}

```

### 总结

重复上述操作，当读取到最后一个字符`#`的时候，由于它的优先级最小，所以不管操作符栈中元素的优先级如何，都将进行解析，最后遇到开始时加入栈中的`#`，解析结束，此时，运算数栈的唯一一个元素就是答案。

总体代码：

```c++
#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;


class Solution {
public:

	char table[9][9] = {   //算符优先级表 
	//           +   -   *   /   ^   !   (   )   #    // 当前运算符
		/* + */	'>','>','<','<','<','<','<','>','>',
		/* - */	'>','>','<','<','<','<','<','>','>',
		/* * */	'>','>','>','>','<','<','<','>','>',
		/* / */	'>','>','>','>','<','<','<','>','>',
		/* ^ */	'>','>','>','>','>','<','<','>','>',
		/* ! */	'>','>','>','>','>','>',' ','>','>',
		/* ( */	'<','<','<','<','<','<','<','=',' ',
		/* ) */	' ',' ',' ',' ',' ',' ',' ',' ',' ',
		/* # */	'<','<','<','<','<','<','<',' ','='
		// 栈顶运算符
	};

	int calculate(string s) {
		s += '#';
		int flag = 0;
		stack<char> OPTR;//操作符栈
		stack<int> OPND;//操作数栈 

		OPTR.push('#');


		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == ' ')
				continue;
			if (isdigit(c)) {
				if (flag) {   //连续数字
					int t = OPND.top();
					OPND.pop();
					t = t * 10 - '0'+ c ;
					OPND.push(t);
				}
				else {
					OPND.push(c - '0');
					flag = 1;
				}
			}
			else {
				flag = 0;
				char opt = OPTR.top();
				switch (orderBetween(opt, c)) {

				case '<'://栈顶运算符优先级更低，则继续进栈
					OPTR.push(c); break;
				case '=':
					OPTR.pop(); break;
				case '>': {
					i--;  //此时栈顶元素的优先级高于当前元素，此时不再进行解析，而是处理已经入栈的值(a的光标拉回到解析这个符号之前)
					OPTR.pop();

					if ('!' == opt) { //一元运算符 
						int num1 = OPND.top();  //第一个运算数
						OPND.pop();
						num1 = evaluate1(num1, opt);
						OPND.push(num1);
					}
					else {//二元运算符 
						int num1 = OPND.top();
						OPND.pop();
						int num2 = OPND.top();
						OPND.pop();

						num1 = evaluate2(num1, opt, num2);
						OPND.push(num1);
					}
					break;
				}
				}
			}
		}
		return OPND.top();
	}

	int factorial(int a) {//求阶乘 
		if (a == 0 || a == 1) {
			return 1;
		}
		if (a < 0) {
			printf("ERROR,Negative number cannot calculate factorial");
			return 0;
		}
		int i, val = 1;
		for (i = a; i > 1; i--) {
			val *= i;
		}
		return val;
	}
	int evaluate1(int a, char opt) {
		if (opt == '!') {
			return factorial(a);
		}
		else {
			printf("ERROR 001");
			return 0;
		}
	}
	int evaluate2(int a, char opt, int b) {
		switch (opt) {
			case '+':
				return a + b;
			case '-':
				return b - a;
			case '*':
				return a * b;
			case '/': {
				if (a == 0) {
					printf("ERROE zero cannot be div");
					return 0;
				}
				return b / a;
			}
			case '^':
				return (int)pow(b, a);
		}
		return -1;
	}

	int getorder(char a) {
		switch (a) {
			case '+':
				return 0;
			case '-':
				return 1;
			case '*':
				return 2;
			case '/':
				return 3;
			case '^':
				return 4;
			case '!':
				return 5;
			case '(':
				return 6;
			case ')':
				return 7;
			case '#':
				return 8;
		}
		return -1;
	}
	char orderBetween(char a, char b) {
		int i, j;
		i = getorder(a);
		j = getorder(b);
		return table[i][j];
	}

};

int main()
{
	Solution s;
	//vector<int> input = { 0,2,3,4,6,8,9 };
	auto a = s.calculate("(1+(4+5+2)-3)+(6+8)");

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}

	//for (auto t : a) {
	//	cout << t << " , ";
	//}

	cout << a << endl;

	return 0;
}

```

---

如果有帮助，记得点一个赞呦 ！！

欢迎访问我的[LeetCode做题笔记](https://github.com/dongzj1997/leetcode),基本每一道题的解析和代码都会以markdown的方式呈现，有什么问题也可以私信我进行讨论。
