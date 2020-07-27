# 977. 有序数组的平方

```c++
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

双指针，简单题，难度不如丑数的`1/10`

注意和丑数一样，也有一个坑，左右两边的值可能想等，根据题意处理即可。

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int pos = lower_bound(A.begin(), A.end(), 0) - A.begin();
        int l = pos - 1, r = pos;
        int len = A.size();
        vector<int> ans;
        while(l >=0 || r < len){
            if(l < 0){
                ans.push_back(A[r]*A[r]);
                r++;
                continue;
            }
            if(r >= len){
                ans.push_back(A[l]*A[l]);
                l--;
                continue;
            }
            int t = min(A[r]*A[r], A[l]*A[l]);
            if(A[r]*A[r] == t){
                ans.push_back(A[r]*A[r]);
                r++;
            }
            if(A[l]*A[l] == t){
                ans.push_back(A[l]*A[l]);
                l--;
            }
        } 
        return ans;
    }
};
```

---
