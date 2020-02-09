# 475-供暖器

```c++
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。

所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。

说明:

给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:

输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: [1,2,3,4],[1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/heaters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

有两种思路：

1. 以房子为出发点，对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离，然后每个房子的距离取最大就是答案。

2. 以供暖器为出发点，求两个相邻供暖器的中值， 寻找该中值左右两边的两个房子，房子到暖器的距离取大值就是这两个供暖器的最小半径。然后遍历一遍暖器，取最大值。

```c++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans =0;
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<houses.size();i++){
            int cur=INT_MAX;
            
            //去寻找右边的供暖器
            // lower_bound 返回第一个大于等于这个元素的迭代器
            auto larger = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            if(larger!=heaters.end())
            {
                cur=*larger-houses[i];
            }
            
            //尝试寻找左边的那个供暖器
            if(larger!=heaters.begin())
            {
                auto smaller=larger-1;
                cur=min(cur,houses[i]-*smaller);
            }
            ans=max(cur,ans);
        }
        return ans;
    }
};
```

---



