# 第 26 场双周赛

链接：https://leetcode-cn.com/contest/biweekly-contest-26/

本来洗了个澡想睡觉的（刚洗完困的不行），突然想起这周还有双周赛，勉强做做吧。

刚开始状态还行，前三题都挺简单的，思路不绕弯，基本上秒过。

```c++
5396. 连续字符 

给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

class Solution {
public:
	int maxPower(string s) {
		int ans = 1;
		int res = 1;
		int  pre = -1;
		for (char c : s) {
			if (int(c) == pre) {
				ans++;
				res = max(res, ans);
			}
			else {
				pre = int(c);
				ans = 1;
			}
		}
		return res;
	}
};

```



第四题的时候刚开始想用回溯，发现超时（还是小看lc的用例强度了）



---

```c++

```

---



