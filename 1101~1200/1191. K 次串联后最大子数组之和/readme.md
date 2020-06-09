# 1191. K 次串联后最大子数组之和

```c++
给你一个整数数组 arr 和一个整数 k。

首先，我们要对该数组进行修改，即把原数组 arr 重复 k 次。

举个例子，如果 arr = [1, 2] 且 k = 3，那么修改后的数组就是 [1, 2, 1, 2, 1, 2]。

然后，请你返回修改后的数组中的最大的子数组之和。

注意，子数组长度可以是 0，在这种情况下它的总和也是 0。

由于 结果可能会很大，所以需要 模（mod） 10^9 + 7 后再返回。 

 

示例 1：

输入：arr = [1,2], k = 3
输出：9
示例 2：

输入：arr = [1,-2,1], k = 5
输出：2
示例 3：

输入：arr = [-1,-2], k = 7
输出：0
 

提示：

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-concatenation-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

分情况讨论，如果数组的全部元素和大于0，则分为头，尾，中部三段，再加上（k-3）个完整数组。

如果数组和小于等于0，则分为两段，头和尾，

分别求对应情况的最大子数组之和即可。

```c++
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int s = 0;
        int M= 1e9+7;
        for(int n:arr){
            s+=n;
        }
        long long ans = 0;
        if(k == 1) return hp(arr);
        if(s > 0 && k >= 3){
            vector<int> t(arr.size() *3);
            for(int i=0;i<arr.size() *3;i++){
                t[i] = arr[ i % arr.size()];
            }
            int re = hp(t);
            ans = (long long)re + (long long)(k-3)*(s%M);

        }else{
            vector<int> t(arr.size() *2);
            for(int i=0;i<arr.size() *2;i++){
                t[i] = arr[ i % arr.size()];
            }
            ans = hp(t);
        }
        return ans % M;
    }

    int hp(vector<int> & arr ){
        int ans = 0;
        int t = 0;
        for(int n:arr){
            ans += n;
            ans = max(ans,n);
            t = max(t, ans);
        }
        return t;
    }
};
```

---



