# 401. 二进制手表

```c++
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。



例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:
```

![img](./Binary_clock_samui_moon.jpg)

```c++


输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

从数字角度遍历0:00 ~11:59

！！！也可以用`n&(n-1)`来计算二进制1的个数

```c++
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> ans;
		for (int i = 0; i <= num; i++) {
			vector<string> Hours = getHours(i);
			vector<string> Minutes = getMinutes(num - i);

			for (auto h : Hours) {
				for (auto m : Minutes) {
					ans.push_back(h + m);
				}
			}
		}
		return ans;
		
	}
	vector<string> getHours(int num) {
		if (num > 4)
			return {};
		vector<vector<string> > ans = {
			{"0:"}, //0位
			{"1:","2:","4:","8:"}, //1位
			{"3:","5:","9:","6:","10:"},//2位
			{"11:","7:"},//3位
			{} //4位
		};

		return ans[num];
	}
	vector<string> getMinutes(int num) {
		vector<string> ans;
		for (int i = 0; i <= 59; i++) {
			bitset<6> bs(i);
			if (bs.count() == num) {
				string t = to_string(i);
				if (i <= 9) {
					t = '0' + t;
				}
				ans.push_back(t);
			}
		}
		return ans;
	}
};

```

---



