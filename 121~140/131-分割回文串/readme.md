# 131. 分割回文串

```c++
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:

	vector<vector<string>> ans;
	string S ="";
	int len = 0;

	vector<vector<string>> partition(string s) {
		S = s;
		len = s.size();

		vector<vector<bool>> dp(len, vector<bool>(len, false));//动态规划数组的生成
		for (int L = 1; L <= len; L++) {  //L 表示要判断是否是回文串的长度
			for (int i = 0; i <= len-L; i++) {
				int j = i + L - 1; //j表示字符串末尾，i为开头
				dp[i][j] = s[i] == s[j] && (L < 3 || dp[i + 1][j - 1]); //动态规划的生成
			}
		}
		partitionHelper(0, dp, vector<string>{});
		return ans;

	}

	void partitionHelper(int start, vector<vector<bool>>& dp, vector<string> temp) {
		if (start == len) { //如果已经检测到字符串结束，将本次遍历的数组加入结果中，返回。
			ans.push_back(temp);
		}
		else {
			//在不同位置切割
			for (int i = start; i < len; i++) {
				//如果是回文串就加到结果中
				if (dp[start][i]) { //从start开始，到i结束
					string left = S.substr(start, i- start + 1);
					temp.push_back(left);
					partitionHelper(i + 1, dp, temp);
					temp.pop_back();

				}
			}
		}
	}
};
```

---

## 使用动态规划减少计算量

首先，断一个字符串是否是回文串的时候，通常做法是调用 isPalindrome 判断。这就会造成一个问题，比如字符串 abbbba，期间我们肯定会判断 bbbb 是不是回文串，也会判断 abbbba 是不是回文串。判断 abbbba 是不是回文串的时候，在 isPalindrome 中依旧会判断中间的 bbbb 部分。而其实如果我们已经知道了 bbbb 是回文串，只需要判断 abbbba 的开头和末尾字符是否相等即可。

所以我们为了避免一些重复判断，可以用动态规划的方法，把所有字符是否是回文串提前存到数组dp中。

```c++
		vector<vector<bool>> dp(len, vector<bool>(len, false));//动态规划数组的生成
		for (int L = 1; L <= len; L++) {  //L 表示要判断是否是回文串的长度
			for (int i = 0; i <= len-L; i++) {
				int j = i + L - 1; //j表示字符串末尾，i为开头
				dp[i][j] = s[i] == s[j] && (L < 3 || dp[i + 1][j - 1]); //动态规划的生成
			}
		}
```

用 `dp[i][j]` 表示 `s[i，j]` 是否是回文串。

然后有 `dp[i][j] = s[i] == s[j] && dp[i+1][j-1]`，对于长度为1，2，3的字符串，直接判断`s[i] == s[j]` 即可（同样防止了边界的溢出） 。

我们只需要两层 for 循环，从每个下标开始，考虑所有长度的子串即可。

---

## 使用回溯生成结果

回溯法其实就是一个 dfs 的过程，每次不断地向深处递归，如果检测到达最深处，则添加本次递归的结果到最终结果中，递归结束以后使用`temp.pop_back();`将本次的值删掉。

---

还有一种分治的解法：

> aabb
>先考虑在第 1 个位置切割，a | abb
>这样我们只需要知道 abb 的所有结果，然后在所有结果的头部把 a 加入
>abb 的所有结果就是 [a b b] [a bb]
>每个结果头部加入 a，就是 [a a b b] [a a bb]
>
>aabb
>再考虑在第 2 个位置切割，aa | bb
>这样我们只需要知道 bb 的所有结果，然后在所有结果的头部把 aa 加入
>bb 的所有结果就是 [b b] [bb]
>每个结果头部加入 aa,就是 [aa b b] [aa bb]
>
>aabb
>再考虑在第 3 个位置切割，aab|b
>因为 aab 不是回文串，所有直接跳过
>
>aabb
>再考虑在第 4 个位置切割，aabb |
>因为 aabb 不是回文串，所有直接跳过
>
>最后所有的结果就是所有的加起来
>[a a b b] [a a bb] [aa b b] [aa bb]

```java
public List<List<String>> partition(String s) {
    return partitionHelper(s, 0);
}

private List<List<String>> partitionHelper(String s, int start) {
    //递归出口，空字符串,如果正常返回，则ans的长度为1
    if (start == s.length()) {
        List<String> list = new ArrayList<>();
        List<List<String>> ans = new ArrayList<>();
        ans.add(list);
        return ans;
    }
    List<List<String>> ans = new ArrayList<>();
    for (int i = start; i < s.length(); i++) {
        //当前切割后是回文串才考虑
        if (isPalindrome(s.substring(start, i + 1))) {
            String left = s.substring(start, i + 1);
            //遍历后边字符串的所有结果，将当前的字符串加到头部
            for (List<String> l : partitionHelper(s, i + 1)) {
                l.add(0, left);
                ans.add(l);
            }
        }

    }
    return ans; //非正常返回，ans的长度为0；
}

private boolean isPalindrome(String s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s.charAt(i) != s.charAt(j)) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

```
