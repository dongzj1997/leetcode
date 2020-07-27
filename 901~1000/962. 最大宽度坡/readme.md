# 962. 最大宽度坡

```c++
给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。

找出 A 中的坡的最大宽度，如果不存在，返回 0 。

 

示例 1：

输入：[6,0,8,2,1,5]
输出：4
解释：
最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
示例 2：

输入：[9,8,1,0,1,9,4,0,4,1]
输出：7
解释：
最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
 

提示：

2 <= A.length <= 50000
0 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-ramp
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1：使用单调栈，然后二分搜索算法 O(n*logn)

这是我第一次做的时候写的方法，时间复杂度为O(n*logn) ，比较费时，大约164 ms左右，击败20%、

基本思路是从后往前查找，利用贪心的思路，记录一些值有大，出现还靠后的节点，同时用一个vector记录从后往前查找中新出现的最大值，所以vector一定是递增的、

查找过程中，如果当前的数为最大值，则说明后续没有比他还大的节点，将该值插入vector中即可。

如果不是最大值，则利用二分的方法寻找vector数组中第一个大于该数的原始，该数的下标与当前的下标之差就是一个可以的结果，

不断寻找最大的结果即可。

```c++
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int> vc, vcc;
        int len = A.size();
        vc.push_back(A[len - 1]); //记录值
        vcc.push_back(len-1); //记录位置
        int ans = 0;
        for (int i = len - 2; i >= 0; i--) {
            if (A[i] > vc.back()) {
                vcc.push_back(i);
                vc.push_back(A[i]);
            }
            else {
                if (A[i] == 1) {
                    int tt = 0;
                }
                int t = lower_bound(vc.begin(), vc.end(), A[i]) - vc.begin();
                int index = vcc[t];
                ans = max(ans, index - i);
            }
        }
        return ans;
    }
};
```

---

## 方法2：带pop的单调栈，时间复杂度O(n)

先使用一个栈s（单调递减的），处理一遍A数组，然后留下的都是又小，出现还早的元素。

扫描时从后往前扫描数组A，将后面的一些小的元素弹出（利用到了贪心的思想，因为如果用这个元素的话，后面的值计算出最后的结果不可能比这个值再大了）不断扫描，求ans的最大值。

```c++
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        for(int i=0;i<A.size();++i){
            if(s.empty()||A[i]<A[s.top()]) s.push(i);
        }
        int ans=0;
        for(int j=A.size()-1;j>ans;--j){
            while(!s.empty()&&A[j]>=A[s.top()]){
                ans=max(ans,j-s.top());
                s.pop();
            }
        }
        return ans;
    }
};
```

看到别人超过100%的提交，加一行神秘代码可以提高30ms。。

```c++
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
```
