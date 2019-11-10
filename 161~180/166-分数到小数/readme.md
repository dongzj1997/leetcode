# 166. 分数到小数

```c++
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long numer = numerator; //numerator
		long long deno = denominator; // denominator

		if (numer == 0) {
			return "0";
		}

		int flag1 = 0, flag2 = 0;
		if (numer < 0) {
			numer *=-1;
			flag1 = 1;
		}

		if (deno < 0) {
			deno *= -1;
			flag2 = 1;
		}

		long long a = numer / deno;  //整数部分
		numer %= deno;

		
		string ans = to_string(a);
		if (flag1 ^ flag2) {
			ans = '-' + ans;
		}
		if(numer == 0){
			return ans;
		}
		ans += '.';
		string temp = "";
		vector<vector<int>> loop(10, vector<int>());
		vector<vector<int>> local(10, vector<int>());

		int i = 0;
		while (numer != 0) {
			numer *= 10;
			int t = numer / deno;

			

			numer %= deno;

			for (int j = 0; j < loop[t].size(); j++) {
				if (loop[t][j] == numer) {  //出现循环
					int loc = local[t][j];// 循环出现的位置
					temp = temp.substr(0, loc) + '(' + temp.substr(loc) + ')';

					return ans + temp;
				}
			}
			temp += to_string(t);
			loop[t].push_back(numer);
			local[t].push_back(i);
			i++;


		}

		return ans + temp;
	}
};
```

---

先上个图：

![img](./1.bmp)

主要思想：

使用`vector<vector<int>> loop(10, vector<int>());`记录得到的商出现过那些余数，如果出现相同的余数，说明循环了。

使用`vector<vector<int>> local(10, vector<int>());`记录循环的位置。

避开一下主要坑点就好了：

1. 会出现负数
2. 会出现0
3. 会出现INT_MIN,导致abs的时候溢出，使用long
