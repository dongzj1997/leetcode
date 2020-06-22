# 1131. 绝对值表达式的最大值

```c++
给你两个长度相等的整数数组，返回下面表达式的最大值：

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

其中下标 i，j 满足 0 <= i, j < arr1.length。

 

示例 1：

输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
输出：13
示例 2：

输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
输出：20
 

提示：

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-of-absolute-value-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

如果是一维，那么`|arr1[i] - arr1[j]|`的最大值，就是`arr1[i]`的最大值 - `arr1[j]`最小值，只需遍历一次。

同样二维`|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]|`有4种情况

如果上升到三维，则有8种情况，分别枚举，然后去一个最大值即可

```c++
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,min4=INT_MAX;
        int n=arr1.size();
        for(int i=0;i<n;i++){
            max1=max(max1,arr1[i]+arr2[i]+i);
            max2=max(max2,-arr1[i]+arr2[i]+i);
            max3=max(max3,arr1[i]-arr2[i]+i);
            max4=max(max4,arr1[i]+arr2[i]-i);
            min1=min(min1,arr1[i]+arr2[i]+i);
            min2=min(min2,-arr1[i]+arr2[i]+i);
            min3=min(min3,arr1[i]-arr2[i]+i);
            min4=min(min4,arr1[i]+arr2[i]-i);
        }
        return max({max1-min1,max2-min2,max3-min3,max4-min4});
    }
};
```

---



