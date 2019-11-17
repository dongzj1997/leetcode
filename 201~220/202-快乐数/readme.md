# 202. 快乐数

```c++
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解法1：常规解法（使用set记录重复数字）

```c++
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> m;
		if (n == 0)
			return false;
		int sum = 0;
		while (n != 1) {
			if (m.count(n) != 0)
				return false;
			else
				m.insert(n) ;
			
			while (n != 0) {
				int t = n % 10;
				n /= 10;
				sum += t * t;
			}
			n = sum;
			sum = 0;
			
		}
		return true;
	}
};
```

---

## 解法2：使用类似快慢指针的做法判断是否有循环（等价于链表有环）

```java
class Solution {
    public boolean isHappy(int n) {
        int fast=n;
        int slow=n;
        do{
            slow=squareSum(slow);
            fast=squareSum(fast);
            fast=squareSum(fast);
        }while(slow!=fast);
        if(fast==1)
            return true;
        else return false;
    }
    
    private int squareSum(int m){
        int squaresum=0;
        while(m!=0){
           squaresum+=(m%10)*(m%10);
            m/=10;
        }
        return squaresum;
    }
}
```