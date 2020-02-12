# 面试题64. 求1+2+…+n

```c++
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
```

---

小学就知道的事情：等差数列和 = (首项+尾项)*项数/2

还知道了高斯和5050这个数

```c++
class Solution {
public:
    int sumNums(int n) {
        return (1+n)*n/2;
    }
};
```

---



