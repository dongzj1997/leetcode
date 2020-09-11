# 932. 漂亮数组

```c++
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：

对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。

那么数组 A 是漂亮数组。

 

给定 N，返回任意漂亮数组 A（保证存在一个）。

 

示例 1：

输入：4
输出：[2,1,4,3]
示例 2：

输入：5
输出：[3,1,2,5,4]
 

提示：

1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

来源[@zerorlis-2](https://leetcode-cn.com/problems/beautiful-array/solution/piao-liang-shu-zu-de-yi-xie-xing-zhi-bing-qie-ji-y/)

>漂亮数组有以下的性质:
>
>（1）A是一个漂亮数组，如果对A中所有元素添加一个常数，那么Ａ还是一个漂亮数组。
>
>（2）A是一个漂亮数组，如果对A中所有元素乘以一个常数，那么A还是一个漂亮数组。
>
>（3）A是一个漂亮数组，如果删除一些A中一些元素，那么A还是一个漂亮数组。
>
>（4) A是一个奇数构成的漂亮数组，B是一个偶数构成的漂亮数组，那么A+B也是一个漂亮数组
>
>比如:{1,5,3,7}+{2,6,4,8}={1,5,3,7,2,6,4,8}也是一个漂亮数组。
>
>所以我们假设一个{1-m}的数组是漂亮数组，可以通过下面的方式构造漂亮数组{1-2m}:
>
>对{1-m}中所有的数乘以2-1，构成一个奇数漂亮数组A。如{1,3,2,4},可以得到{1,5,3,7}
>
>对{1-m}中所有的数乘以2,构成一个偶数漂亮数组B,如{1,3,2,4}, 可以得到{2,6,4,8}
>
>A+B构成了{1-2m}的漂亮数组。{1,5,3,7}+{2,6,4,8}={1,5,3,7,2,6,4,8}
>
>从中删除不要的数字即可。

```c++
class Solution {
public:
    vector<int> beautifulArray(int N) {
        // 比较小的数字直接返回。
        if (N == 1) return {1};
        if (N == 2) return {1, 2};
        if (N == 3) return {1, 3, 2};
        if (N == 4) return {1, 3, 2, 4};
        // 从{1,3,2,4}，4个数字开始构建漂亮数组，当然从{1}开始构建也可以
        vector<int> temp = {1, 3, 2, 4};
        while (temp.size() < N) {
            for (auto& i : temp) {
                i = i * 2 - 1;
            }
            int s = temp.size();
            for (int i = 0; i < s; i++) {
                temp.push_back(temp[i] + 1);
            }
        }
        // 删除不需要的数字
        temp.erase(remove_if(temp.begin(), temp.end(), [=](int i) { return i > N; }), temp.end());
        return temp;
    }
};

```

---

