# 1054. 距离相等的条形码

```c++
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

 

示例 1：

输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：

输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
 

提示：

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distant-barcodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

方法1， 先填奇数的位置，后填偶数的位置（填充的数要按出现次数大到小排列，防止中间出现重合的情况（如`[1,2,2,3]`））

方法2， hash_map计数+priority_map模拟，每次取数量最多(top1)和次多(top2)的形成一个不相邻的pair加入到ans中。时间复杂度：O(nlogn)，空间复杂度O(n)。

```c++
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int len = barcodes.size();
        map<int, int> mp;
        for (int n : barcodes) {
            mp[n]++;
        }

        vector<pair<int, int>> vp;
        for (auto p : mp) {
            vp.push_back(p);
        }
        sort(vp.begin(), vp.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });


        vector<int> ans(len, 0);

        int idx = 0;
        for (auto p : vp) {
            int n = p.first;
            int cnt = p.second;
            for (int i = 0; i < cnt; i++) {
                ans[idx] = n;
                idx += 2;
                if (idx >= len) idx = 1;
            }
        }
        return ans;

    }
};
```

---

