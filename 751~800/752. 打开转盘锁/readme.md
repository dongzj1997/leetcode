# 752. 打开转盘锁

```c++
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
```

---

广度优先遍历

后续改进：双向搜索，每次搜索集合元素少的那个集合

```c++
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> mp;
        unordered_map<string,int> ban;
        for(auto s : deadends){
            ban[s] = 1;
        }
        if(ban["0000"] == 1) return -1;
        queue<string> q;
        q.push("0000");
        mp["0000"] = 1;
        int depth = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto s= q.front();
                q.pop();
                if(ban[s] == 1) continue;
                if(s == target) return depth;
                for(int i=0;i<4;i++){
                    string s1 = s;
                    string s2 = s;
                    s1[i] = s1[i] == '9' ? '0' : s1[i] + 1;
                    s2[i] = s2[i] == '0' ? '9' : s2[i] - 1;
                    if(mp[s1] != 1){
                        q.push(s1);
                        mp[s1] = 1;
                    }
                    if(mp[s2] != 1){
                         q.push(s2);
                        mp[s2] = 1;
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
```

---



