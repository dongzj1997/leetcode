# 593. 有效的正方形

```c++
给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。

一个点的坐标（x，y）由一个有两个整数的整数数组表示。

示例:

输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
 

注意:

所有输入整数都在 [-10000，10000] 范围内。
一个有效的正方形有四个等长的正长和四个等角（90度角）。
输入点没有顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

有位仁兄说排序以后可以直接判断`destent[0] == destent[3]`，省两个判断。

也太细了吧。

```c++
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> destent;
        destent.push_back(getDest(p1, p2));
        destent.push_back(getDest(p1, p3));
        destent.push_back(getDest(p1, p4));
        destent.push_back(getDest(p2, p3));
        destent.push_back(getDest(p2, p4));
        destent.push_back(getDest(p3, p4));
        sort(destent.begin(),destent.end());
        if(destent[0] <= 0.00000001) return false;
        return abs(destent[0] - destent[1]) + abs(destent[0] - destent[2]) + abs(destent[0] - destent[3])  <= 0.00001;
        
    }
    double getDest(vector<int>& p1, vector<int>& p2){
        return pow((p1[1] - p2[1]),2)+pow( (p1[0] - p2[0]),2 );
    }
};
```

---



