# 917. 仅仅反转字母

```c++
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

出题已经到了山穷水尽的地步了吗，我已经是第n次见这种题了。

```c++
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.size();
        int l=0,r=len-1;
        while(l<r){
            while(l < len && !isalpha(S[l])) l++;
            while(r >=0 && !isalpha(S[r])) r--;
            if(l<r) swap(S[l++],S[r--]);
        }
        return S;
    }
};
```

---

