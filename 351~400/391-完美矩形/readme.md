# 391. 完美矩形

```c++
我们有 N 个与坐标轴对齐的矩形, 其中 N > 0, 判断它们是否能精确地覆盖一个矩形区域。

每个矩形用左下角的点和右上角的点的坐标来表示。例如， 一个单位正方形可以表示为 [1,1,2,2]。 ( 左下角的点的坐标为 (1, 1) 以及右上角的点的坐标为 (2, 2) )。



示例 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

返回 true。5个矩形一起可以精确地覆盖一个矩形区域。
 



示例 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

返回 false。两个矩形之间有间隔，无法覆盖成一个矩形。
 



示例 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

返回 false。图形顶端留有间隔，无法覆盖成一个矩形。
 



示例 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

返回 false。因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

>如果是完美矩形 那么一定满足两点： （1）最左下 最左上 最右下 最右上 的四个点只出现一次 其他点成对出现 （2）四个点围城的矩形面积 = 小矩形的面积之和

```c++
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX; //左上
        int y1 = INT_MAX; //右上
        int x2 = INT_MIN; //左下
        int y2 = INT_MIN; //右下
        int area = 0;
        set<pair<int,int>> points;
        
        for(auto r : rectangles){
            
            //最后大矩形的四个坐标
            x1 = min(x1,r[0]);
            y1 = min(y1,r[1]);
            x2 = max(x2,r[2]);
            y2 = max(y2,r[3]);
            
            area += abs(r[2]-r[0])*abs(r[3]-r[1]);// 小矩形的面积
            
            pair<int,int> p1 = make_pair(r[0],r[1]);
            pair<int,int> p2 = make_pair(r[0],r[3]);
            pair<int,int> p3 = make_pair(r[2],r[1]);
            pair<int,int> p4 = make_pair(r[2],r[3]);
            
            
            //如果点出现过，则擦去，否则插入
            if(!points.count(p1)){
                points.insert(p1);
            }else{
                points.erase(p1);
            }
            if(!points.count(p2)){
                points.insert(p2);
            }else{
                points.erase(p2);
            }
            if(!points.count(p3)){
                points.insert(p3);
            }else{
                points.erase(p3);
            }
            if(!points.count(p4)){
                points.insert(p4);
            }else{
                points.erase(p4);
            }
        }
        
        //检查面积是否亏或者盈
        if(area != abs(x2-x1)*abs(y2-y1)){
            return false;
        }
        
        //剩下的刚好是哪四个点
        if(points.count(make_pair(x1,y1))&&
           points.count(make_pair(x1,y2))&&
           points.count(make_pair(x2,y1))&&
           points.count(make_pair(x2,y2))&&
           points.size() == 4){
            return true;
        }else{
            return false;    
        }
    }
};

```

---



