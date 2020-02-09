# 412-Fizz Buzz

```c++
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fizz-buzz
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

难度：简单

```c++
class Solution {
public:
    vector<string> fizzBuzz(int& n) {
        vector<string> ans(n,"");
        for (int i = 1; i <= n; i++){
            if (!(i % 3))
                ans[i-1] += "Fizz";
            if (!(i % 5))
                ans[i-1] += "Buzz";
            if(!ans[i-1].size())
                ans[i-1] += to_string(i);
        }
        return ans;
    }
};
```

---



