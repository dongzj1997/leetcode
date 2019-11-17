# 242. 有效的字母异位词

```c++
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

开一个数组，记录每个字母出现的次数，如果在第一个字符串中出现，则+1.在第二个字符串中出现，则-1

最后为全0，表示刚好抵消，两个字符串字母异位

```c++
class Solution {
public:
	bool isAnagram(string s, string t) {
		int ans[26] = {0};
		if (s.size() != t.size())
			return false;
		for (int i = 0; i < s.size(); i++) {
			ans[s[i] - 'a']++;
			ans[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (ans[i] != 0)
				return false;
		}
		return true;
	}
};
```

简单
