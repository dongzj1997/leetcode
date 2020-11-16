# 38. 外观数列

```c++
给定一个正整数 n ，输出外观数列的第 n 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1 
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
要 描述 一个数字字符串，首先要将字符串分割为 最小 数量的组，每个组都由连续的最多 相同字符 组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。

例如，数字字符串 "3322251" 的描述如下图：


 

示例 1：

输入：n = 1
输出："1"
解释：这是一个基本样例。
示例 2：

输入：n = 4
输出："1211"
解释：
countAndSay(1) = "1"
countAndSay(2) = 读 "1" = 一 个 1 = "11"
countAndSay(3) = 读 "11" = 二 个 1 = "21"
countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
 

提示：

1 <= n <= 30

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

名字改了，以前叫报数 来着。。

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<math.h>
#include <algorithm> 

using namespace std;
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了91.17%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了76.60%的用户
*/

class Solution {
public:
	string countAndSay(int n) {
		n--;
		string s1 = "1";
		string s2="";
		for (int i = 0; i < n; i++) {
			int len = s1.size();

			char t = s1[0];
			int count = 0;
			for (int j = 0; j < len; j++) {  //对每一个字符
				if (s1[j] != t) {
					string tempstr = to_string(count) + t;
					s2.append(tempstr);
					count = 1;
					t = s1[j];
				}
				else {
					count++;
				}
			}
			string tempstr = to_string(count) + t;
			s2.append(tempstr);
			s1 = s2;
			s2 = "";
			//cout << s1 << endl;
		}
		return s1;
	}
};

int main()
{
	Solution s = Solution();
	string sss = "1234";
	char ss[] = "1234";
	auto ans = s.countAndSay(4);
	
	cout << ans << endl;

	return 0;
}
```

---
