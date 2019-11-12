# 168. Excel表列名称

```c++
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-title
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	string convertToTitle(int n) {
		string ans = "";

		while (n > 0) {
			n--;
			char c = n % 26 +'A';
			ans += c;
			n = n / 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
```

---

![img](./1.bmp)

## 解题

这道题乍一看像是26进制转换的问题，但是 A~Z 对应的是 1~26 ，简单的除法实际上映射的是0~25，所以对循环的每一次，都将n--，即可完成。
