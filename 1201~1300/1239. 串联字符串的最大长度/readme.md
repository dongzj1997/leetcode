# 1239. 串联字符串的最大长度

```c++
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26
 

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母
通过次数9,693提交次数24,596

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

不用回溯法写了一个解题，执行用时 :212 ms, 在所有 C++ 提交中击败了34.21%的用户

这也太慢了

```c++
class Solution {
public:

    int maxLength(vector<string>& arr) {
        int ans = 0;
        int len = arr.size();
        for (int i = 1; i < (1 << len); i++) {
            int t = i;
            int cnt = 0;
            int idx = 0;
            int mask = 0;

            while (t != 0) {
                if (t & 1) {
                    string st = arr[idx];
                    for (char c : st) {
                        if ((mask & (1 << (c - 'a'))) == 0) {
                            mask |= (1 << (c - 'a'));
                            cnt++;
                        }
                        else {
                            goto L;
                        }
                    }
                }
                t >>= 1;
                idx++;

            }
            ans = max(cnt, ans);
        L:          int dd = 0;
        }
        return ans;
    }
};
```

---

评论区的回溯法又快又简单

```c++
class Solution {
public:
    int backtrace(vector<string>& arr, int i, int m) {
        if (i == arr.size()) {
            return 0;
        }
        int t = m;
        for (char c : arr[i]) {
            if (m & (1 << (c-'a'))) {
                return backtrace(arr, i+1, t);
            }
            m |= (1 << (c - 'a'));
        }
        int len = arr[i].length();
        return max(len + backtrace(arr, i+1, m), backtrace(arr, i+1, t));
    }
    int maxLength(vector<string>& arr) {
        return backtrace(arr, 0, 0);
    }
};
```