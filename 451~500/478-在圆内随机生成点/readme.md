# 478-在圆内随机生成点

```c++
给定圆的半径和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint 。

说明:

输入值和输出值都将是浮点数。
圆的半径和圆心的 x、y 坐标将作为参数传递给类的构造函数。
圆周上的点也认为是在圆中。
randPoint 返回一个包含随机点的x坐标和y坐标的大小为2的数组。
示例 1：

输入: 
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
输出: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
示例 2：

输入: 
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
输出: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-random-point-in-a-circle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

拒绝采样

除此之外，极坐标的方法也可以

```c++
class Solution {
public:
    double r,x,y;
    default_random_engine e;
	uniform_real_distribution<double> u{0, 1};
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x =x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        
        double randx,randy;

        do{
            randx = u(e)* 2 * r -r + x;
            randy = u(e)* 2 * r -r + y;
        }while((randx - x)*(randx - x)+(randy-y)*(randy-y) > r*r);
        
        return {randx  ,randy };

    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
```

---



