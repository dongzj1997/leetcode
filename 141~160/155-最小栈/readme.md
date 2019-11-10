# 155. 最小栈

```c++
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class MinStack {
public:
	stack<int> st1;  //存储栈
	stack<int> st2;  //储存最小值

	MinStack() {

	}

	void push(int x) {
		st1.push(x);

		if (st2.empty() || x < st2.top()) {
			st2.push(x);
		}
		else {
			st2.push(st2.top());
		}
	}

	void pop() {
		st1.pop();
		st2.pop();
	}

	int top() {
		return st1.top();
	}

	int getMin() {
		return st2.top();
	}
};
```

---

使用两个栈st1和st2，一个记录真实值，一个记录从当前位置到栈底的最小值。
