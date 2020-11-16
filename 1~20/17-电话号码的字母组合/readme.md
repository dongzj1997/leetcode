# 17. 电话号码的字母组合

```c++
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		//                  0     1     2                               7
		vector<string> a{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		//                  2     3     4                               9
		int deep = 0;
		int maxdeep = digits.length()-1;
		vector<string> ans;
		if (maxdeep == -1) {
			return ans;
		}
		
		ans.push_back("");  // 手动向ans中添加一个数，使得算法可以启动
		//string t(digits.length(),' ' );  //先将每次得出的字符串构造好，防止多次重复追加浪费时间。

		for (int j = 0; j <= maxdeep; j++) { //从左到右增加每个按键
			int len = ans.size(); //之前所有按键的情况组合数
			for (int i = 0; i < len; i++) {
				//按键的每个情况，在之前结果上加上一个按键
				for (auto m : a[digits[j]-'2'])
				{
					ans.push_back(ans[i] + m);
				}
			}
			//删除上一步中残留的项
			ans.erase(ans.begin(), ans.begin() + len);

		}
		return  ans;
	}
};
```

---
