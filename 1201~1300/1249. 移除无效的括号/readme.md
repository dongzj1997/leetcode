# 1249. 移除无效的括号

```c++
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"
 

提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母
通过次数6,530提交次数11,674

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

使用栈ss来记录每个左括号出现的位置。

扫描时，如果出现右括号，这和最近的左括号抵消，如果没有，则说明这个右括号是多余的，将其变为一个空格。

扫描结束后，栈中剩余的左括号为多余的，将其变为空格。

将所有的空格去掉，生成最终的字符串。

```c++
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.size();
        stack<int> ss;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                ss.push(i);
            }
            else if(s[i] == ')'){
                if(ss.size()){
                    ss.pop();
                }else{
                    s[i] = ' ';
                }
            }
        }
        while(ss.size()){
            s[ss.top()] = ' ';
            ss.pop();
        }
        string ans;
        for(int i=0;i<len;i++){
            if(s[i] != ' ')
                ans += s[i];
        }

        return ans;
    }
};
```

---



