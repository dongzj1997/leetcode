# 905. 按奇偶排序数组

```c++
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

比较像快排中根据数轴交换数的代码

```c++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        int l = 0, r = len-1;
        while(l < r){
            while(l < len && (A[l] & 1) != 1) l++;
            while(r >=0 && (A[r] & 1) == 1) r--;
            if(l < r) swap(A[l++], A[r--]);
        }
        return A;
    }
};
```

---
