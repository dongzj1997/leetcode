给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

执行用时 :4 ms, 在所有 C++ 提交中击败了97.71%的用户
内存消耗 :17.2 MB, 在所有 C++ 提交中击败了61.76%的用户

思路类似于生成n位二进制数，只不过要做相应的判断
时间复杂度为卡特兰数，详细解析见：

 https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode/

还有闭合数的相关方法也很精巧

使用动态规划的方法也可以求解：

https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/


甚至数组找规律的方法：

https://leetcode-cn.com/problems/generate-parentheses/solution/jiang-ke-neng-chu-xian-de-wei-zhi-ji-ci-shu-yong-y/