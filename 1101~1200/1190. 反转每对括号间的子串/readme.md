# 1190. 反转每对括号间的子串

```c++
给出一个字符串 s（仅含有小写英文字母和括号）。

请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

注意，您的结果中 不应 包含任何括号。

 

示例 1：

输入：s = "(abcd)"
输出："dcba"
示例 2：

输入：s = "(u(love)i)"
输出："iloveu"
示例 3：

输入：s = "(ed(et(oc))el)"
输出："leetcode"
示例 4：

输入：s = "a(bcdefghijkl(mno)p)q"
输出："apmnolkjihgfedcbq"
 

提示：

0 <= s.length <= 2000
s 中只有小写英文字母和括号
我们确保所有括号都是成对出现的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

栈的基础题，扫描字符串，遇到`(`时将新的字符串入栈，遇到`)`时将栈顶的字符串倒序加入（委托）到上一层的栈中，

遇到普通字符时候直接将字符添加到栈顶字符串的末尾。

超过100%

```c++
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> sk;
        sk.push("");
        for(char c:s){
            if(c == '('){
                sk.push("");
            }
            else if( c == ')'){
                string t= sk.top();
                sk.pop();
                for(int i = t.size() -1 ; i >=0;i--){
                    sk.top() += t[i];
                }
            }else{
                sk.top() += c;
            }
        }
        string t= sk.top();
        //reverse(t.begin(), t.end());
        return t;
    }
};
```

---



