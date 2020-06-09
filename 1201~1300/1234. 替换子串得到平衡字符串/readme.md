# 1234. 替换子串得到平衡字符串

```c++
有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。

假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。

 

给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。

你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。

请返回待替换子串的最小可能长度。

如果原字符串自身就是一个平衡字符串，则返回 0。

 

示例 1：

输入：s = "QWER"
输出：0
解释：s 已经是平衡的了。
示例 2：

输入：s = "QQWE"
输出：1
解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
示例 3：

输入：s = "QQQW"
输出：2
解释：我们可以把前面的 "QQ" 替换成 "ER"。 
示例 4：

输入：s = "QQQQ"
输出：3
解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 

提示：

1 <= s.length <= 10^5
s.length 是 4 的倍数
s 中只含有 'Q', 'W', 'E', 'R' 四种字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

滑动窗口
```c++
class Solution {
public:
    int balancedString(string s) {
        map<char, int> mp;
        mp['Q'] = 0, mp['W'] = 1, mp['E'] = 2, mp['R'] = 3;
        
        //a 表示窗口外这个元素有多少个
        int a[4] = {0};
        int len = s.size();
        for(int i=0;i<len;i++){
            a[mp[s[i]]]++;
        }
        int l = 0,r = 0, ans = len;
        int ave = len/4;
        while(r < len){
            a[mp[s[r]]]--; //滑动窗口里进来一个元素,对应的a减1
            while(l < len && a[0] <= ave && a[1] <= ave&& a[2] <= ave && a[3]<= ave ){
                ans = min(ans, r - l  + 1) ;
                a[mp[s[l++]]]++;
            }
            r++;
        }
        return ans;
    }
};
```

---

