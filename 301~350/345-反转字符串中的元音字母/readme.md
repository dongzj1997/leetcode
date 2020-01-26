# 345. 反转字符串中的元音字母

```c++
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.size() - 1;
		int dict[128] = { 0 };
		string target = "aoeiuAOEIU";
		for (char c : target) {
			dict[c] = 1;
		}

		while (i < j)
		{
			while (dict[s[i]] == 0 && i < j)
				i++;
			while (dict[s[j]] == 0 && i < j)
				j--;
			if (i < j) {
				swap(s[i], s[j]);
				i++;
				j--;
			}
				
		}
		return s;
	}
};
```

---



