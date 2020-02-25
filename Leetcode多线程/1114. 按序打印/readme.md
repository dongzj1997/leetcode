# 1114. 按序打印

```c++
我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}
三个不同的线程将会共用一个 Foo 实例。

线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

 

示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释: 
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。
示例 2:

输入: [1,3,2]
输出: "onetwothree"
解释: 
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-in-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1--自定义信号量+while阻塞

1680 ms, 在所有 C++ 提交中击败了5.05%的用户

```c++
class Foo {
public:
    volatile int sign1 = 0;
    volatile int sign2 = 0;
    
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sign1 = 1;
    }

    void second(function<void()> printSecond) {
        while(sign1 == 0){
            
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sign2 = 1;
    }

    void third(function<void()> printThird) {
        while(sign2 == 0){
            
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
```

---



