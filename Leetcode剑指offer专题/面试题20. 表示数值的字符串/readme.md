# 面试题20. 表示数值的字符串

```c++
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及"-1E-16"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

 

注意：本题与主站 65 题相同：https://leetcode-cn.com/problems/valid-number/

通过次数883提交次数4,756

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

一图胜千言,来源leetcode官方解题

![123](./1.png)

```c++
class Solution {
public:
	int state = 0;
	int transfer[9][5] ={ 
		{ 0, 1, 6, 2,-1},
		{-1,-1, 6, 2,-1},
		{-1,-1, 3,-1,-1},
		{ 8,-1, 3,-1, 4},
		{-1, 7, 5,-1,-1},
		{ 8,-1, 5,-1,-1},
		{ 8,-1, 6, 3, 4},
		{-1,-1, 5,-1,-1},
		{ 8,-1,-1,-1,-1}  
	};


	bool isNumber(string s) {

		for(auto c : s){
            int id = getId(c);
            if(id == -1)
                return 0;
            state = transfer[state][id];
            
            if(state == -1)
                return 0;
        }

		if (state == 3 || state == 5 || state == 6 || state == 8) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int getId(char c) {
		if (c >= 48 && c <= 57) 
			return 2;
		switch (c) {
			case ' ': return 0;
			case '+':
			case '-': return 1;
			case '.': return 3;
			case 'e': return 4;
			default:
				return -1;
		}
	}
};
/*
state	blank	+/-	  0-9	   .	   e	 other
0	      0	      1	   6	    2	  -1      -1
1	     -1	     -1	   6	    2	  -1      -1
2	     -1	     -1	   3	   -1	  -1      -1
3	      8	     -1	   3	   -1	   4	  -1
4	     -1	      7	   5	   -1	  -1      -1
5	      8	     -1	   5	   -1	  -1      -1
6	      8	     -1	   6	    3	   4	  -1
7	     -1	     -1	   5	   -1	  -1      -1
8	      8	     -1	  -1	   -1	  -1      -1
状态图详见https://pic.leetcode-cn.com/0683d701f2948a2bd8c235867c21a3aed5977691f129ecf34d681d43d57e339c-DFA.jpg						 
*/
```

---



