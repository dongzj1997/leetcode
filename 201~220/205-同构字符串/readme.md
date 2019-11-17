# 205. 同构字符串

```c++
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int s1[128] = {0};
		int s2[128] = {0};

		for (int i = 0; i < s.size(); i++) {
			if (s1[int(s[i])] != s2[int(t[i])])
				return false;
			s1[int(s[i])] = i+1;
			s2[int(t[i])] = i+1;
		}
		return true;
	}
};

```

---

s1[128] 记录上一个相同字符出现的位置，为了避免出现位置为0和没出现过混淆，特地做了一次偏移`s1[int(s[i])] = i+1;`。
