# 480. 滑动窗口中位数

```c++
中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3

[2,3]，中位数是 (2 + 3) / 2 = 2.5

给出一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

 

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

思路和代码来自leetcode官方解题：

类似于295题，使用两个堆来处理数据量一直在变的集合中的中位数。

与之不同的是，要删除元素的时候，使用延迟删除的方法，第一次删除的时候仅改变两个堆的平衡值，等到该元素暴露在堆顶的时候才真正的将其删除。

```c++
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<double> ans;
        unordered_map<int, int> hash_table;

        //使用堆来维护这个滑动窗口 
        priority_queue<int> lo;                                 // 一个大根堆 lo，用来存放较小的那一半的元素
        priority_queue<int, vector<int>, greater<int> > hi;     // 一个小根堆 hi，用来存放较大的那一半的元素

        int i = 0;      // index of current incoming element being processed

        // 初始化窗口
        while (i < k)
            lo.push(nums[i++]);
        for (int j = 0; j < k / 2; j++) {
            hi.push(lo.top());
            lo.pop();
        }

        while (true) {
            // get median of current window
            //k = 2n + 1 为奇数，那么 lo 中存储 k + 1 个元素，hi 中存储 k 个元素；，中位数为lo的顶
            //k = 2n 为偶数，那么 lo 和 hi 中都存储 k 个元素，中位数为两个堆顶的平均值
            ans.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

            if (i >= nums.size())
                break;                          // break if all elements processed

            int out_num = nums[i - k],          // outgoing element
                in_num = nums[i++],             // incoming element
                balance = 0;                    // balance factor

            // number `out_num` exits window
            // 判断要弹出的数在lo堆还是在hi堆，执行-1或者+1的操作
            balance += (out_num <= lo.top() ? -1 : 1);
            hash_table[out_num]++;

            // number `in_num` enters window
            if (!lo.empty() && in_num <= lo.top()) { //插入的元素属于小堆
                balance++;
                lo.push(in_num);
            }
            else {
                balance--;
                hi.push(in_num);
            }

            // re-balance heaps
            if (balance < 0) {                  // `lo` needs more valid elements
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if (balance > 0) {                  // `hi` needs more valid elements
                hi.push(lo.top());
                lo.pop();
                balance--;
            }

            // remove invalid numbers that should be discarded from heap tops
            //检测堆顶，查看是否有已经弹出的元素
            while (hash_table[lo.top()]) {
                hash_table[lo.top()]--;
                lo.pop();
            }
            while (!hi.empty() && hash_table[hi.top()]) {
                hash_table[hi.top()]--;
                hi.pop();
            }
        }

        return ans;
    }

};
```

---



