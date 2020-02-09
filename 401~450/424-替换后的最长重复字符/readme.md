# 424-替换后的最长重复字符

```c++
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意:
字符串长度 和 k 不会超过 104。

示例 1:

输入:
s = "ABAB", k = 2

输出:
4

解释:
用两个'A'替换为两个'B',反之亦然。
示例 2:

输入:
s = "AABABBA", k = 1

输出:
4

解释:
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

一次AC，感觉良好。

使用双指针的方法，不断试图扩大窗口大小（如果失败，则将窗口右移一个单位）

改变窗口的时候要注意更新dict数组

```c++
class Solution {
public:
	int dict[26] = { 0 }; //存储当前窗口中每一类字母的个数
	int characterReplacement(string s, int k) {
		int len = s.size();
		if (len <= k + 1)
			return len;

		int ans = k + 1;
		
		int left = 0;
		int right = k;

		//窗口的初始化
		for (int i = left; i <= right; i++) {  //初始一共k+1 个元素
			dict[s[i] - 'A']++;
		}

		//窗口滑动
		while (right < len) {
			int maxNum = gitMax();
			if (maxNum + k >= right - left + 1) { //说明可以
				ans = right - left + 1;
				right++;
				if (right < len)
					dict[s[right] - 'A']++;
			}
			else {
				dict[s[left] - 'A']--;
				right++;
				left++;
				if (right < len)
					dict[s[right] - 'A']++;

			}
		}

		return ans;
	}

	int gitMax() {
		int m = 0;
		for (int i = 0; i < 26; i++) {
			m = max(m, dict[i]);
		}
		return m;
	}
};

```

---

## 改进gitMax函数

该函数时间复杂度位O(1)，虽然不大，但是调用多次还是很影响时间

其实只要比较上一次的max_count 和这一次新增的字符即可。


```c++
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int max_count=0,l=0,r;
        vector<int> count(128,0);
        for(r=0;r<s.size();r++)
        {
            max_count=max(max_count,++count[s[r]]);
            if(r-l+1-max_count>k)
                count[s[l++]]--;
        }
        return r-l;
    }
};
```

