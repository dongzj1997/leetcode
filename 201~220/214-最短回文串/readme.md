# 214. 最短回文串

```c++
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
示例 2:

输入: "abcd"
输出: "dcbabcd"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

对于原始字符串 `abcd`，我们将它倒过来 `dcba`，然后加到原字符串前面，成为`dcbaabcd`，一定是回文。

但是显然不是最短的回文(aa重复，其实只需要`dcbabcd`就可以了)，其实我们需要找到dcba的后缀和abcd的前缀重合的部分，且让重合部分最大即可。

这恰好就是KMP算法中求NEXT数组的过程。

还需要注意，我们所求的前缀不能超过中点，因此用`#`号隔开，然后将字符换一下位置，为`abcd#dcba`，这样就是一个标准的求NEXT数组的过程（求后缀和前缀相同的长度）

在求得最大相同长度以后，后半部分除去重叠的部分然后拼接到前半部分（即原字符串）即可

```c++

class Solution {
public:
	string shortestPalindrome(string s) {  //假如存进去的字符串是  "abcd"
		string revs = s;//存s的逆序 
		reverse(revs.begin(), revs.end());  //revs为   "bcba"

		int mid = s.size();  //中点处,#前面的位置
		//                                                 . = mid
		s = ' ' + s + '#' + revs;//让下标从1开始, s为 " abcd#bcda"
		//这样就转化为了求s字符串next数组的问题

		int len = s.size() - 1;//总长度
		vector<int> next(len + 1);//next数组
		for (int i = 2, j = 0; i <= len; i++) {//求next数组 
			while (j && s[i] != s[j + 1]) j = next[j];
			if (s[i] == s[j + 1]) j++;
			next[i] = j;
		}
		return s.substr(mid + 2, mid - next[len]) + s.substr(1, mid);//后半部分除去重叠后缀+前半部分（原字符串）
	}

};

```

---

