# 557. 反转字符串中的单词 III

```c++
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

c++的string为了兼容c风格的字符串，会在最后加一个`/0` 这是标准。

```c++
class Solution {
public:
	string reverseWords(string s) {
		int len = s.size();
		int l = 0;
		for (int i = 0; i < len + 1; i++){
			if (s[i] == ' ' || s[i] == '\0'){
				for (int r = i - 1; l < r; l++, r--){
					swap(s[l], s[r]);
				}
				l = i + 1;
			}
		}
		return s;
	}
};

```

---
