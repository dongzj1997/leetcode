# 面试题31. 栈的压入、弹出序列

```c++

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。
注意：本题与主站 946 题相同：https://leetcode-cn.com/problems/validate-stack-sequences/
```

---

根据火车站来改的

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_map<int , int> mp;
        int index = 0;
        for(int n:pushed){
            mp[n] = index++;
        }
        for(int &n: popped)
            n = mp[n];
        
		int len = popped.size();
		vector<bool> visited(len + 1, false);
		
		for (int i = 0; i < len - 1; i++) {        
			visited[popped[i]] = true;
			if (popped[i + 1] < popped[i]) { 
				int k = 0;
				for (int j = popped[i + 1] + 1; j < popped[i]; j++) {
					if (visited[j] == false) {
						return false;
					}
				}
			}
		}
		return true;
	}
};
```

---

另一种方法，模拟法（来自@luheng）

```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        """
        True的条件，pointer指向popper的最后一个
        相等的时候，pointer往后一位，stack，pop掉一位
        不相等的时候，pushed往后一位，stack加一位
        """
        pointer = 0
        stack = []
        for num in pushed:
            stack.append(num)
            while stack and stack[-1] == popped[pointer]:
                stack.pop()
                pointer+=1
        return pointer == len(popped)
```

---



