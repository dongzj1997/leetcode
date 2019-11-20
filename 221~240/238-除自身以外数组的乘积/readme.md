# 238. 除自身以外数组的乘积

```c++
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len =nums.size();
        vector<int> ans(len, 0);
        int k = 1;
        for(int i = 0; i < len; i++){
            ans[i] = k;  //注意此处不是 *=
            k *= nums[i]; // 此时数组存储的是除去当前元素左边的元素乘积
        }
        k = 1;
        for(int i = len - 1; i >= 0; i--){
            ans[i] *= k; // k为该数右边的乘积。   注意此处为 *=
            k *= nums[i]; // 此时数组等于左边的 * 该数右边的。
        }
        return ans;

    }
};
```

---

[乘积 = 当前数左边的乘积 * 当前数右边的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/solution/cheng-ji-dang-qian-shu-zuo-bian-de-cheng-ji-dang-q/)



