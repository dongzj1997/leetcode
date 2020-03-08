# 633. 平方数之和

```c++
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
 

示例2:

输入: 3
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

左右逼近

```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        int j = sqrt(c);
        int i=0;
        long a =i*i,b=j*j;
        while(i<=j){
            long t = a + b;
            if(t > c){
                j--;
                b = j*j;
            }else if(c >t){
                i++;
                a = i*i;
            }else
                return true;
        }
        return false;
    }
};
```

---



