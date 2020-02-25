# 1195. 交替打印字符串

```c++
编写一个可以从 1 到 n 输出代表这个数字的字符串的程序，但是：

如果这个数字可以被 3 整除，输出 "fizz"。
如果这个数字可以被 5 整除，输出 "buzz"。
如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"。
例如，当 n = 15，输出： 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz。

假设有这么一个类：

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
请你实现一个有四个线程的多线程版  FizzBuzz， 同一个 FizzBuzz 实例会被如下四个线程使用：

线程A将调用 fizz() 来判断是否能被 3 整除，如果可以，则输出 fizz。
线程B将调用 buzz() 来判断是否能被 5 整除，如果可以，则输出 buzz。
线程C将调用 fizzbuzz() 来判断是否同时能被 3 和 5 整除，如果可以，则输出 fizzbuzz。
线程D将调用 number() 来实现输出既不能被 3 整除也不能被 5 整除的数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fizz-buzz-multithreaded
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这题存疑，代码来自评论区

```c++
class FizzBuzz {
private:
    int n;
    int x = 1;
    mutex m1,m2,m3,m4;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(x <= n){
            m2.lock();
            if(x > n)
                return;
            if(x % 3 == 0){
                printFizz();
                ++x;
                m1.unlock();
            }
            else{
                m3.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(x <= n)
        {
            m3.lock();
            if(x > n)
                return;
            if(x % 5 == 0){
                printBuzz();
                ++x;
                m1.unlock();
            }
            else{
                m4.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(x <= n)
        {
            m1.lock();
            if(x > n)
                break;
            if(x % 3 == 0 && x % 5 == 0){
                printFizzBuzz();
                ++x;
                m1.unlock();
            }
            else{
                m2.unlock();
            }
        }
        m2.unlock();
        m3.unlock();
        m4.unlock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(x <= n)
        {
            m4.lock();
            if(x > n)
                return;
            printNumber(x);
            ++x;
            m1.unlock();
        }
    }
};
```

---



