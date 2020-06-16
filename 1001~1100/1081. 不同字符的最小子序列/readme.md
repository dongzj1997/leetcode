# 1081. 不同字符的最小子序列

```c++
返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

 

示例 1：

输入："cdadabcc"
输出："adbc"
示例 2：

输入："abcd"
输出："abcd"
示例 3：

输入："ecbacba"
输出："eacb"
示例 4：

输入："leetcode"
输出："letcod"
 

提示：

1 <= text.length <= 1000
text 由小写英文字母组成
 

注意：本题目与 316 https://leetcode-cn.com/problems/remove-duplicate-letters/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

单调栈!

```c++
class Solution {
public:
    string smallestSubsequence(string text) {
        int cnt[26] = {0};
        bool pin[26] = {false};
        for(char c: text){ 
            cnt[c-'a']++; 
        }
        string ans;
        for(char c: text){
            int n = c-'a';
            cnt[n]--;
            if(pin[n]) continue;
            while(ans.size() && cnt[ans.back()- 'a'] != 0 && ans.back() > c){
                pin[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += c;
            pin[n] = true;
        }
        return ans;
    }
};
```

---

