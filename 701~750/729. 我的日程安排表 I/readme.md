# 729. 我的日程安排表 I

```c++
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。

MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。

当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。

每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

示例 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
解释: 
第一个日程安排可以添加到日历中.  第二个日程安排不能添加到日历中，因为时间 15 已经被第一个日程安排预定了。
第三个日程安排可以添加到日历中，因为第一个日程安排并不包含时间 20 。
说明:

每个测试用例，调用 MyCalendar.book 函数最多不超过 100次。
调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。
```

---

## C++ 有关二分查找的三个函数

1. `lower_bound(起始地址，结束地址，要查找的数值)`.在first和last中的前闭后开区间进行二分查找，返回**大于或等于val**的第一个元素位置。如果所有元素都小于val，则返回last的位置. 注意：如果所有元素都小于val，则返回last的位置，且last的位置是越界的！

2. `upper_bound(起始地址，结束地址，要查找的数值)`返回的在前闭后开区间查找的关键字的上界，返回**大于val**的第一个元素位置

3. `binary_search(起始地址，结束地址，要查找的数值)`  返回的是是否存在这么一个数，是一个bool值。

注意，只要是有序迭代的容器，都可以使用这三个函数（如set，map等）。

```c++
class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        st.insert({INT_MIN,INT_MIN});
        st.insert({INT_MAX,INT_MAX});
    }
    
    bool book(int start, int end) {
        auto p = st.lower_bound({start,end});
        if(p->first < end) 
            return false;
        if((--p)->second > start ) 
            return false;
        st.insert({start,end});
        return true;
    }
};
```

---



