# 780. 到达终点

```c++
从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。

给定一个起点 (sx, sy) 和一个终点 (tx, ty)，如果通过一系列的转换可以从起点到达终点，则返回 True ，否则返回 False。

示例:
输入: sx = 1, sy = 1, tx = 3, ty = 5
输出: True
解释:
可以通过以下一系列转换从起点转换到终点：
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

输入: sx = 1, sy = 1, tx = 2, ty = 2
输出: False

输入: sx = 1, sy = 1, tx = 1, ty = 1
输出: True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reaching-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

>刚开始一直超时，看了@he style的解题恍然大悟：
>
>大部分的人一般都会惯性思维死劲想着怎么从(sx, sy)推到(tx, ty)，
>
>蛋式由于可以变换的情况非常多，特别是当起点与终点的差距比较大的时候。如果我们逆向思考呢，
>
>从(tx, ty)推到(sx, sy)，则时只能有一种操作，就是将tx、ty中较大值减去较小值（因为顺推的时候是(x, y)
>
> 可以转换到 (x, x+y) 或者 (x+y, y)，则逆推的时候只能将较大者减去较小者），这样思维方式确实很妙！
>
>
>当然光有这远远不够，这时我们得考虑优化代码了，在进行将较大值减去较小值的时候，当tx，ty的差距非常大 这时就需要大量的耗时，那我们能不能将较大者一次性减去若干个>较小值，从而快速 逼近sx，sy呢？详见下面的代码。

```c++
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0){//因为sx, sy, tx, ty 是范围在 [1, 10^9] 的整数，逆推不能出界
            if (sx == tx && sy == ty){//判断是否到达了起始值
                return true;
            }
            //每次逆推只能有tx、ty中较大值减去若干个较小值
            if (tx > ty){//此时只能有tx减去ty
                //tx - sx是目标与起始值在x的差距，我们需要一次减去n * ty达到快速逼近sx的目的
                tx -= max((tx - sx) / ty, 1) * ty;
            }
            else{//此时只能有ty减去tx
                //ty - sy是目标与起始值在y的差距，我们需要一次减去n * tx达到快速逼近sy的目的
                ty -= max((ty - sy) / tx, 1) * tx;
            }
        }
        return false;
    }
};
/*
--------------------- 
作者：hestyle 
来源：CSDN 
原文：https://blog.csdn.net/qq_41855420/article/details/90079900 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
```

```c++
class Solution {
public:
    // 3 3 12 9     3 9
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > 0 && ty > 0){
            if(sx == tx && sy == ty) return true;
            if( tx > ty){
                 tx -= max((tx - sx) / ty, 1) * ty;
            }else{
                ty -= max((ty - sy) / tx, 1) * tx;
            }
        }
        return false;
    }
};
```

---



