# 914. 卡牌分组

```c++
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

辗转相除

```c++
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int mp[10001] = {0};
        for(int n:deck){
            mp[n]++;
        }
        int x = 0;
        for(int i=0;i<10001;i++){
            if(mp[i] > 0){
                x = gcd(x, mp[i]);
                if(x == 1) return false;
            }
        }
        return true;
    }
    
    int gcd(int a, int b){
        if(b == 0) return a;
        else {
            return gcd(b,a%b);
        }
    }
};
```

---



