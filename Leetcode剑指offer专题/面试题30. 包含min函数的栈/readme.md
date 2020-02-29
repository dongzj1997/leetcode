# 面试题30. 包含min函数的栈

```c++

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次
```

---

信手拈来



```c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top() >= x)
            s2.push(x);
    }

    void pop() {
        int t = s1.top();
        s1.pop();
        if (t == s2.top())
            s2.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};
```

---



