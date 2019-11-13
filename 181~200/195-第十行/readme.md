# 195. 第十行

```c++
给定一个文本文件 file.txt，请只打印这个文件中的第十行。

示例:

假设 file.txt 有如下内容：

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
你的脚本应当显示第十行：

Line 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tenth-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---
可以使用：

```bash
awk 'NR == 10' file.txt        # NR在awk中指行号

sed -n 10p file.txt -n         #表示只输出匹配行，p表示Print

tail -n +10 file.txt|head -n 1 # tail -n +10表示从第10行开始输出

```

---



