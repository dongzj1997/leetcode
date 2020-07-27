# 955. 删列造序 II

```c++
给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["abcdef", "uvwxyz"]，删除索引序列 {0, 2, 3}，删除后 A 为["bef", "vyz"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的元素是按 字典序（A[0] <= A[1] <= A[2] ... <= A[A.length - 1]）排列的，然后请你返回 D.length 的最小可能值。

 

示例 1：

输入：["ca","bb","ac"]
输出：1
解释： 
删除第一列后，A = ["a", "b", "c"]。
现在 A 中元素是按字典排列的 (即，A[0] <= A[1] <= A[2])。
我们至少需要进行 1 次删除，因为最初 A 不是按字典序排列的，所以答案是 1。
示例 2：

输入：["xc","yb","za"]
输出：0
解释：
A 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 A 的行不需要按字典序排列。
也就是说，A[0][0] <= A[0][1] <= ... 不一定成立。
示例 3：

输入：["zyx","wvu","tsr"]
输出：3
解释：
我们必须删掉每一列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-columns-to-make-sorted-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

第一次把题意理解错了，浪费了一些时间。

不是每一列都需要严格有序，而是每一列组成的字符串之间需要有序。

如果第一列都能把序排出来了，就不用考虑后面的列了。

所以使用一个数组vb记录当时那些列还没有排出来，每次排序即可。

```c++
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size();
        int n = A[0].size();
        int ans = 0;
        vector<bool> vb(m, true);
        for(int i=0;i<n;i++){
            bool flag = 1;
            for(int j=0;j<m-1;j++){
                if(vb[j] && A[j][i] > A[j+1][i]){
                    ans++;
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(int j=0;j<m-1;j++){
                    if(A[j][i] < A[j+1][i]){
                        vb[j] = false;
                    }
                }  
            }
        }
        return ans;
    }
};



```

---
