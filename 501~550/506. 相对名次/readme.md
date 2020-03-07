# 506. 相对名次

```c++
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

评论区（mikiyashiki）的方法，实现一个order函数

### 1. order()与rank()的区别：

```r
test <- c(2,4,3,1)
order(test) #4 1 3 2, order是将结果按值的大小一个个抽取出来，如先抽第4个元素1
rank(test) #2 4 3 1
```

### 2. 排序的写法

`[&nums](const int& a,const int& b){return nums[a] > nums[b];}`

```c++
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order(nums.size(),0);
        vector<string> res(nums.size());
        
        for(int i=0;i<nums.size();i++){
            order[i] = i;
        }
        
        sort(order.begin(),order.end(),[&nums](const int& a,const int& b){return nums[a] > nums[b];});
        
        for(int i=0;i<nums.size();i++){
            switch(i)
            {
                case 0:res[order[i]]="Gold Medal";break;
                case 1:res[order[i]]="Silver Medal";break;
                case 2:res[order[i]]="Bronze Medal";break;
                default:res[order[i]]=to_string(i+1);break;
            }
        }
        
        return res;
    }
};
```

---



