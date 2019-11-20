# 223-矩形面积

```c++
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
```

![a](./rectangle_area.png)

```c++
示例:

输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s = 0;
        if (E >= C || G <= A || H <= B || F >= D) {
            s = 0;
        } else {
            int x1 = max(A, E);
            int x2 = min(C, G);
        
            int y1 = max(B, F);
            int y2 = min(D, H);
        
            s = (x2 - x1) * (y2 - y1);
        }
        //long ans = (long)(C-A) * (D-B) + (long)(G-E) * (H-F) - (long)s;
        
        return (C-A) * (D-B) - s + (G-E) * (H-F) ;
    }
};
```

---

两个矩形的面积减去重叠的面积

注意：使用`return (C-A) * (D-B) - s + (G-E) * (H-F) ; `先减后加防止溢出

