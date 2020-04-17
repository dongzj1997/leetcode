# 777. 在LR字符串中交换相邻字符

```c++
在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。

示例 :

输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
输出: True
解释:
我们可以通过以下几步将start转换成end:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
注意:

1 <= len(start) = len(end) <= 10000。
start和end中的字符串仅限于'L', 'R'和'X'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-adjacent-in-lr-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

来自评论区一年前（今2020年3月28日）的思路(@he style)

> 思路分析： 题目的意思是说 ‘R’只能向右移动，并且只能移向’X’，‘L’只能向左移动，并且只能移向’X’。

> 第一：如果将start、end中的‘X’全部去掉得到的newStart 和 newEnd相等才有可能转换成功。

>第二：如果start中'R'的左边'X'的个数超过在end中对应位置的'R'的左边'X'的个数，则不能转换成功，因为start中的'R'只能向右移动，右边的'X'只能增加不能减少

>第三：如果end中'L'的左边'X'的个数超过在start中对应位置的'L'的左边'X'的个数，则不能转换成功，因为start中的'L'只能向左移动，左边的'X'只能减少不能增加

777 世界聚焦于你！

```c++
class Solution {
public:
    bool canTransform(string start, string end) {
        int strSize = (int)start.size(), i = 0, j = 0;
        while(i < strSize && j < strSize){
            while (i < strSize && start[i] == 'X'){
                i++;
            }
            while (j < strSize && end[j] == 'X'){
                j++;
            }
            if (start[i] != end[j]){
                return false;
            }
            //检测start中'L'左边'X'的个数是否不少于end中对应位置的'L'左边的'X'个数
            //检测start中'R'左边'X'的个数是否不多余end中对应位置的'R'左边的'X'个数
            if ((start[i] == 'L' && i < j) || (end[j] == 'R' && i > j)){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
```

---



