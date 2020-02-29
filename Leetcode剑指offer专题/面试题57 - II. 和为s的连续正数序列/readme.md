# 面试题57 - II. 和为s的连续正数序列

```c++
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析一 左右滑动窗口法

没有难度

## 解析二 数学计算法

数学方法求解，思路来源 [@magic_conch](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/c-0msshu-xue-jie-fa-by-magic_conch/)


`start`加到`end` `=` `target`，那么有`(start+end)*(end-start+1)/2 = target`

其实就是简单的等差数列求和，为了简单起见，我们将*2去掉，直接求符合`(start+end)*(end-start+1) = target * 2`条件的`start`和`end`。

也就是将`start`加到`end`再倒着写一遍，倒序相加，两两之和为`start+end`,一共有`end-start+1`项，相乘即为`target * 2`。

现在的情况就是试着找到所有符合条件的`start`和`end`。

我们将项数记为`i`，则两两之和为`target*2/i`，记为`s`，发现`start`和`end`可以通过项数`i`计算出来，计算公式为`start = (s-i+1)/2, end = (s+i-1)/2`

所以我们先确定`i`,再将所有其他值通过`target`和`i`计算出来，找出满足条件的就好。

需要符合以下条件：

1. `i`能被`target*2`整除
2. 通过`i`计算出的`start`和`end`也都是整数 ---->  通过公式可以转化为 `i`和`s`的奇偶性不同
3. `start`必须是大于`0`的数

实现过程中，`i`从大到小循环，依此判断即可。

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector <vector<int>> ans;
        target*=2;
        for(int i=target/2-1;i>=2;i--){
            if(target%i==0 && ((i%2)^(target/i%2)) && target/i > i  ){
                vector<int> tmp;
                int start = (target/i-i+1)/2,end = (target/i+i-1)/2;
                for(int j=start;j<=end;j++)
                    tmp.push_back(j);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

```

---

## 解析三

和 [829. 连续整数求和](https://leetcode-cn.com/problems/consecutive-numbers-sum/)
差不多

来自 @[yybeta](https://leetcode-cn.com/problems/consecutive-numbers-sum/solution/pythonchao-hao-li-jie-de-onsuan-fa-by-yybeta/)太强了 为什么能这么强

```python
    def consecutiveNumbersSum(self, N: int) -> int:
        # 1个数时，必然有一个数可构成N
        # 2个数若要构成N，第2个数与第1个数差为1，N减掉这个1能整除2则能由商与商+1构成N
        # 3个数若要构成N，第2个数与第1个数差为1，第3个数与第1个数的差为2，N减掉1再减掉2能整除3则能由商、商+1与商+2构成N
        # 依次内推，当商即第1个数小于等于0时结束
        res, i = 0, 1
        while N > 0:
            res += N % i == 0
            N -= i
            i += 1
        return res
```

