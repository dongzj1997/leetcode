# 125. 验证回文串

```c++
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.size();
		if (len == 0)
			return true;
		int i = 0, j = len - 1;
		
		while (i <= j) {
			if (!isalpha(s[i]) && !isdigit(s[i])) {
				i++;
				continue;
			}
			if (!isalpha(s[j]) && !isdigit(s[j])) {
				j--;
				continue;
			}
			if (tolower(s[i]) != tolower(s[j]))
				return false;
			else {
				i++;
				j--;
			}

		}
		return true;
	}
};

```

---

c++双指针，直到两个指针重叠时才返回真，否则返回假。

分享个字母大小写转换的方法：

统一转成大写：ch & 0b11011111 简写：ch & 0xDF  
统一转成小写：ch | 0b00100000 简写：ch | 0x20  
比较的时候注意加上小括号哦，因为位运算优先级比较低。  

使用示例：

```c++
if((s.charAt(i ++) & 0xDF) != (s.charAt(j --) & 0xDF)) return false;
```
