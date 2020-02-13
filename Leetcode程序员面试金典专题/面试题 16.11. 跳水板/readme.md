# 面试题 16.11. 跳水板

```c++
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：

输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diving-board-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

提交前看看数据边界值，k == 0， shorter == longer等情况分开讨论就可以

```c++
class Solution {
public:
	vector<int> divingBoard(int shorter, int longer, int k) {
		if (k == 0)
			return {};
		vector<int> ans;
		if (shorter == longer)
			ans.push_back(shorter * k);
		else {
			for (int i = 0; i <= k; i++) {
				ans.push_back(longer * i + shorter * (k - i));
			}
		}
		return ans;
	}
};
```

---



