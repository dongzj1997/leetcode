# 1013. 将数组分成和相等的三个部分

```c++
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

奇怪的解法

```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int a:A)
            sum+=a;
        
        if(sum % 3 != 0) return false;
        sum /= 3;
        
        int cs = 0, cnt = 0, len = A.size();
        for(int i=0;i<len;i++){
            cs += A[i];
            if(cs == sum){
                cnt++;
                cs = 0;
            }
        }
        //cout << cnt <<" " << cs <<endl;
        return cnt >= 3 && cs == 0;
        
    }
};
```

---



