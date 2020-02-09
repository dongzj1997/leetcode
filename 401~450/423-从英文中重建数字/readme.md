# 423-从英文中重建数字

```c++
给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。

注意:

输入只包含小写英文字母。
输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
输入字符串的长度小于 50,000。
示例 1:

输入: "owoztneoer"

输出: "012" (zeroonetwo)
示例 2:

输入: "fviefuro"

输出: "45" (fourfive)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    string originalDigits(string s) {
        int dict[10] = {0};
        for (char c:s){
            if (c == 'z')     dict[0]++;
            else if (c == 'w')dict[2]++;
            else if (c == 'x')dict[6]++;
            else if (c == 's')dict[7]++;//six & seven
            else if (c == 'g')dict[8]++;
            else if (c == 'u')dict[4]++;
            else if (c == 'f')dict[5]++;//four & five
            else if (c == 'h')dict[3]++;//three & eight
            else if (c == 'i')dict[9]++;//five & six & eight & nine
            else if (c == 'o')dict[1]++;//zero & one & two & four
        }
        dict[7] -= dict[6];
        dict[5] -= dict[4];
        dict[3] -= dict[8];
        dict[9] -= dict[5] + dict[6] + dict[8];
        dict[1] -= dict[0] + dict[2] + dict[4];

        string ans = "";
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < dict[i]; j++)
            {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
```

---



