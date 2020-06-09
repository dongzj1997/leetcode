# 1262. 可被三整除的最大和

```c++
给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。

 

示例 1：

输入：nums = [3,6,5,1,8]
输出：18
解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
示例 2：

输入：nums = [4]
输出：0
解释：4 不能被 3 整除，所以无法选出数字，返回 0。
示例 3：

输入：nums = [1,2,3,4,4]
输出：12
解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
 

提示：

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-sum-divisible-by-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

有点意思的一个题，关键在于不断的dp取最大值。

```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // a, b, c 分别代表之前 %3 余0， 余1，余2 的最大值
        int a = 0, b = INT_MIN, c = INT_MIN;
        for (auto n : nums) {
            int ta = a, tb = b, tc = c;
            if (n % 3 == 0) { //这次的n刚好可以整除3
                a += n;
                b += n;
                c += n;
            }
            else if (n % 3 == 1) { //n对 3 余 1
                a = max(ta, tc + n);
                b = max(tb, ta + n);
                c = max(tc, tb + n);
            }
            else if (n % 3 == 2) { //n对 3 余 2
                a = max(ta, tb + n);
                b = max(tb, tc + n);
                c = max(tc, ta + n);
            }
        }
        return a;
    }
};
```

---



