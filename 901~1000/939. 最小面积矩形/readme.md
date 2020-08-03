# 939. 最小面积矩形

```c++
给定在 xy 平面上的一组点，确定由这些点组成的矩形的最小面积，其中矩形的边平行于 x 轴和 y 轴。

如果没有任何矩形，就返回 0。

 

示例 1：

输入：[[1,1],[1,3],[3,1],[3,3],[2,2]]
输出：4
示例 2：

输入：[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
输出：2
 

提示：

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
所有的点都是不同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-area-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

方法1，使用map或者set遍历所有点，判断是否为长方形

以x轴为基准，首先拿出来x出现两次以上的点，然后遍历这两个点再y轴中的情况

如果这两个点在y轴中也有长度相等的对应点，则算作一个长方形，记录最小值

注意剪支，如果已经找出一组y中相等的点，就没必要其他的点了，直接处理下一个x中出现两次以上的点即可。

执行用时：672 ms, 在所有 C++ 提交中击败了69.40%的用户

```c++
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mps1;
        unordered_map<int, set<int>> mps2;
        for(auto& point:points){
            mps1[point[0]].insert(point[1]);
            mps2[point[1]].insert(point[0]);
        }
        int ans = INT_MAX;
        for(auto & t: mps1){
            int left = t.first;
            auto& ss = t.second;
            if(ss.size() < 2) continue;
            for(auto i = ss.begin(); i!=ss.end();i++){
                auto j = i;

                for(j++; j != ss.end();j++){
                    auto & st1 = mps2[*i];
                    auto & st2 = mps2[*j];
                    bool flag = 0;
                    for(auto n = st1.begin(); n != st1.end();n++){
                        if((*n)  <= left) continue;
                        for(auto m = st2.begin(); m != st2.end();m++){
                            if((*n) == (*m)){
                                ans = min(ans, abs(*i - *j) * abs(*n - left)  );
                                flag = 1;
                                break;
                            }
                        }
                        if(flag)
                            break;
                    }
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
```

---

除此之外，还可以使用枚举对角线的方法，

>我们将所有点放入集合中，并枚举矩形对角线上的两个点，并判断另外两个点是否出现在集合中。例如我们在枚举到 (1, 1) 和 (5, 5) 时，我们需要判断 (1, 5) 和 (5, 1) 是否也出现在集合中。
