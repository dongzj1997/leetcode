# 面试题66. 构建乘积数组

```c++
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

不用额外使用内存，

刚开始速度不行，发现是调试的输出语句忘记注释了

```c++
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> ans(len, 1);
        for(int i = 1;i < len; i++){
            ans[i] = ans[i - 1] * a[i - 1];
            //cout<< ans[i]<<endl;
        }
        int t = 1;
        for(int i = len -1 ;i >=0;i--){
            ans[i] = t * ans[i];
            t *= a[i];
        }
        
        return ans;
    }
};
```

---



