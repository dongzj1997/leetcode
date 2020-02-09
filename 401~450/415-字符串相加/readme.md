# 415. 字符串相加

```c++
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

记得2015秋天做NOJ-100题的时候，一个大数加法和大数乘法我写了好久，提交了N次，代码布满了补丁。

结果刚才随手几分钟就写完了，没测试就提交，一次AC。

还是熟能生巧

```c++
class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;
		int carry = 0;
		int len1 = num1.size(), len2 = num2.size();
		for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
			int a = 0, b = 0;
			if (i >= 0) {
				a = num1[i] - '0';
			}
			if (j >= 0) {
				b = num2[j] - '0';
			}
			int sum = a + b + carry;
			carry = sum / 10;
			sum %= 10;
			ans = char(sum + '0') + ans;
		}

		if (carry) {
			ans = char(carry + '0') + ans;
		}
		return ans;

	}
};
```

---



