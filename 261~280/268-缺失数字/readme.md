# 268. 缺失数字

```c++
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

### 解法1（来自孟舆 Milo CYNING 大神）

和只出现一次的数字，有异曲同工之处。

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
```

---

### 解法2 求和(注意防止溢出)

```c++
//直接将所有数相加会有溢出风险
//边加边减
int sum=0;
int i;
for(i=0;i<nums.size();i++){
    sum+=nums[i]-i;
}
sum-=i;
return abs(sum);
```

其他非O（n）或者需要额外空间的解法就不赘述了
