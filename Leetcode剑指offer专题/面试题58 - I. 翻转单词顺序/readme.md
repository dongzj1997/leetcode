# 面试题58 - I. 翻转单词顺序

```c++
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

翻转两次

```c++
class Solution {
public:
	int true_begin = 0, true_end = 0;

	string reverseWords(string s) {
		
		
		reverse(s.begin(), s.end());
		s += ' ';
		int len = s.size();
		int begin = 0,end=0;
		

		int flag = 0;
		int flag2 = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == ' ') {
				if (flag == 0) { //说明遇到的是连续空格
					begin++;
					continue;
				}
				else {   //在字母后面第一次出现空格
					my_reverse(s, begin, i-1);
					begin = i+1;
					flag = 0;
				}
			}
			else {  //遇到的是字母
				flag = 1;
				flag2 = 1;
			}
		}
		if (flag2 == 0) {
			return "";
		}

		return s.substr(0, true_begin-1);
	}

	void my_reverse(string& s, int begin, int  end) {
		int offsent = 0;
		for (int i = end; i > true_begin + (end - true_begin)/2; i--) {
			swap(s[true_begin + offsent], s[i]);
			offsent++;
		}
		true_begin += end - begin + 1;
		s[true_begin] = ' ';
		true_begin++;
	}
};
```

---



