# 面试题09. 用两个栈实现队列

```c++
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

将栈s1都弹空才考虑插入新数据，插入时一次将s2用完

```c++
class CQueue {
public:
	stack<int> s1;
	stack<int> s2;
	CQueue() {

	}

	void appendTail(int value) {
		s2.push(value);
	}

	int deleteHead() {
		if (s1.empty() && s2.empty())
			return -1;
		if (s1.empty()) {
			while (!s2.empty()) {
				auto t = s2.top();
				s2.pop();
				s1.push(t);
			}
		}

		auto t = s1.top();
		s1.pop();
		return t;
	}
};
```

---



