# 504. 七进制数

```c++
给定一个整数，将其转化为7进制，并以字符串形式输出。

示例 1:

输入: 100
输出: "202"
示例 2:

输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/base-7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool sign = num >= 0;
        if(num == 0)
            return "0";
        num = abs(num);
        int t = 7;
        while(num > 0){
            int b = num % t;
            num /= 7;
            ans += '0' + b;
        }
        
        reverse(ans.begin(), ans.end());
        return sign ? ans: '-' + ans;
    }
};
```

---



