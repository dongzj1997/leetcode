# 458-可怜的小猪

```c++
有 1000 只水桶，其中有且只有一桶装的含有毒药，其余装的都是水。它们从外观看起来都一样。如果小猪喝了毒药，它会在 15 分钟内死去。

问题来了，如果需要你在一小时内，弄清楚哪只水桶含有毒药，你最少需要多少只猪？

回答这个问题，并为下列的进阶问题编写一个通用算法。

 

进阶:

假设有 n 只水桶，猪饮水中毒后会在 m 分钟内死亡，你需要多少猪（x）就能在 p 分钟内找出 “有毒” 水桶？这 n 只水桶里有且仅有一只有毒的桶。

 

提示：

可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
小猪喝完水后，必须有 m 分钟的冷却时间。在这段时间里，只允许观察，而不允许继续饮水。
任何给定的桶都可以无限次采样（无限数量的猪）。
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/poor-pigs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

一只猪可以在`0min 15min 30min 45min`时喝水，可以直接验证`4`桶水

如果喝了上述`4`桶还没死，说明有毒的一定是第`5`桶，所以实际上可以验证`5`桶水。

即`int d = minutesToTest/minutesToDie + 1;`

2只猪以测试`5^2 = 25`桶水，如下：

图片来源：leetcode官方

![img](./1.png)

两边取对数，可以得到`int pig = ceil(log(buckets)/log(d));`

```c++
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int d = minutesToTest/minutesToDie + 1;
        int pig = ceil(log(buckets)/log(d));
        return pig;
    }
};
```

---



