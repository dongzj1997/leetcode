# 1157. 子数组中占绝大多数的元素

```c++
实现一个 MajorityChecker 的类，它应该具有下述几个 API：

MajorityChecker(int[] arr) 会用给定的数组 arr 来构造一个 MajorityChecker 的实例。
int query(int left, int right, int threshold) 有这么几个参数：
0 <= left <= right < arr.length 表示数组 arr 的子数组的长度。
2 * threshold > right - left + 1，也就是说阈值 threshold 始终比子序列长度的一半还要大。
每次查询 query(...) 会返回在 arr[left], arr[left+1], ..., arr[right] 中至少出现阈值次数 threshold 的元素，如果不存在这样的元素，就返回 -1。

 

示例：

MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // 返回 1
majorityChecker.query(0,3,3); // 返回 -1
majorityChecker.query(2,3,2); // 返回 2
 

提示：

1 <= arr.length <= 20000
1 <= arr[i] <= 20000
对于每次查询，0 <= left <= right < len(arr)
对于每次查询，2 * threshold > right - left + 1
查询次数最多为 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-majority-element-in-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

正确的做法是用线段数，记录每一段中元素出现的个数

但是记录每个数的索引，然后使用二分查找这个方法也可以过。大约700ms,击败33%

```c++
class MajorityChecker {
public:
    unordered_map<int, vector<int>> idx;
    
    MajorityChecker(vector<int>& arr) {
        for (auto i = 0; i < arr.size(); ++i) idx[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
        for (auto &i : idx) {
            if (i.second.size() < threshold) continue;
            auto it1 = lower_bound(i.second.begin(), i.second.end(), left);
            auto it2 = upper_bound(i.second.begin(), i.second.end(), right);
            if (it2 - it1 >= threshold) return i.first;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```

---

