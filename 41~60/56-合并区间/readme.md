# 56-合并区间

这道题关键是对 vector<vector<int>> 进行排序。

由于给的数据结构是数对，有些方法将原本的vector<vector<int>>转为速度较快的std::pair 进行处理，其实没有必要。

排序时，根据要排序的数据不同，需要自己编写排序函数，这样不仅能写出更灵活的排序方式，也可以加快程序的运行速度。

```C++
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	}

    sort(intervals.begin(), intervals.end(),cmp);
```

结果：

| 说明 | 用时| 内存 |
| ----  |----  |----  |
|使用自定义cmp函数|16 ms|12.3 MB|
|未使用自定义cmp函数|36 ms|12.2 MB|
