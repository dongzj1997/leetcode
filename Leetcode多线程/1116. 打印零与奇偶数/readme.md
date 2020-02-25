# 1116. 打印零与奇偶数

```c++
1116. 打印零与奇偶数
假设有这么一个类：

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // 构造函数
  public void zero(printNumber) { ... }  // 仅打印出 0
  public void even(printNumber) { ... }  // 仅打印出 偶数
  public void odd(printNumber) { ... }   // 仅打印出 奇数
}
相同的一个 ZeroEvenOdd 类实例将会传递给三个不同的线程：

线程 A 将调用 zero()，它只输出 0 。
线程 B 将调用 even()，它只输出偶数。
线程 C 将调用 odd()，它只输出奇数。
每个线程都有一个 printNumber 方法来输出一个整数。请修改给出的代码以输出整数序列 010203040506... ，其中序列的长度必须为 2n。

 

示例 1：

输入：n = 2
输出："0102"
说明：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
示例 2：

输入：n = 5
输出："0102030405"
```

---

用四个🔒，`m_zero,m_num,m_odd,m_even;`，打印完0以后释放打印数字🔒，在获得数字🔒之前需要或者odd🔒或者even🔒来防止死🔒。

一定要先获得odd🔒或者even🔒然后再请求数字🔒。

```c++
class ZeroEvenOdd {
private:
    int n;
    mutex m_zero,m_num,m_odd,m_even;
    int o = 1;
    int e = 2;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m_num.lock();
        m_even.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
            m_zero.lock();
            printNumber(0);
            m_num.unlock();

        }

        
    }

    void even(function<void(int)> printNumber) {
        while(e<=n){
            m_even.lock();
            m_num.lock();
            printNumber(e);
            e+=2;
            m_zero.unlock();
            m_odd.unlock();            
        }

        
    }

    void odd(function<void(int)> printNumber) {
        while(o<=n){
            m_odd.lock();
            m_num.lock();
            printNumber(o);
            o+=2;
            m_zero.unlock();
            m_even.unlock();
        }

    }
};
```

---



