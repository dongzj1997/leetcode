# 841. 钥匙和房间

```c++
有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:  
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
示例 2：

输入：[[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keys-and-rooms
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单的bds

```c++
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int cnt = 1, len = rooms.size();
        vector<bool> vit (len, false);
        vit[0] = true;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(int a : rooms[t]){
                if(!vit[a]){
                    q.push(a);
                    vit[a] = true;
                    cnt++;
                }
            }
        }
        
        return cnt == len;
            
    }
};
```

---



