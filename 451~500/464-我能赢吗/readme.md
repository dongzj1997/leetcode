# 464. 我能赢吗

```c++
在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

示例：

输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-i-win
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

[@he-style](https://leetcode-cn.com/u/he-style/) 在评论区提供的代码

最关键的是`!canWin(length, nowTarget - (i + 1), cur | used, myMap)`这个语句

由于是双方轮流下子，所以我下完子以后，保证`我必赢` = `对方必输`。

所以进入下一层（另一个人下子）需要返回的值为`false`，才能保证我返回的是`true`。

```c++
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //第一种特殊情况，第一个人选一次即可到达预期值
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        //第二种特殊情况，所有元素的和都小于预期值，则永远无法赢
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }
        unordered_map<int, bool> myMap;
        return canWin(maxChoosableInteger, desiredTotal, 0, myMap);
    }
    //由于maxChoosableInteger 不会大于 20，所以可以使用一个int型的各个位标记是否使用
    //myMap[used]用于标记在使用used（二进制各个位真值代表某个元素是否已经使用，比如used = “1101”代表使用了1，3，4）情况本次挑选是否能赢
    bool canWin(int length, int nowTarget, int used, unordered_map<int, bool>& myMap) {
        if (myMap.count(used)) {
            //如果之前搜索过
            return myMap[used];
        }
        //穷举当前可选的元素
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);//第i位表示选择[1,2,3, maxChoosableInteger]选择i + 1这个值
            if ((cur & used) == 0) {//这个值没有使用过
                //nowTarget <= i + 1是代表已经达到预期值
                //nowTarget - (i + 1)表示选择了i + 1
                //cur | used代表更新各个元素使用情况，使用i + 1，将used的第i位（从第到高）标记为1
                //!canWin(length, total - (i + 1), cur | used, myMap)表示的是对方选择输了
                if (nowTarget <= i + 1 || !canWin(length, nowTarget - (i + 1), cur | used, myMap)) {
                    myMap[used] = true;
                    return true;
                }
            }
        }
        myMap[used] = false;
        return false;
    }
};
```

---



