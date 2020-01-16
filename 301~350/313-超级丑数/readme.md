# 313. 超级丑数

```c++
编写一段程序来查找第 n 个超级丑数。

超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

和之前的丑数ii 差不多，注意指针的使用

```c++
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ans(n, INT_MAX);
		ans[0] = 1;
		vector<int> index(primes.size(), 0);//存储的是primes中的某个数现在的倍数是多少（ans[index]）

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < primes.size(); j++) {
				ans[i] = min(ans[i], ans[index[j]] * primes[j]);
			}

			for (int j = 0; j < primes.size(); j++) {
				if (ans[i] == ans[index[j]] * primes[j]) {
					index[j]++;
				}
			}

			//cout << ans[i] << endl;
		}

		return ans[n-1];
	}

};
```

---

只循环一次的解法：

```c++

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int rst = 1;
        vector<int> tmp;
        tmp.push_back(1);
        vector<int> flag(primes.size(), 0);
        vector<int> f2(primes.size(), 1);

        for (int i = 1; i < n; i++) {
            int minn = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                if (tmp[i - 1] == f2[j]) f2[j] = primes[j] * tmp[flag[j]++];
                minn = min(minn, f2[j]);
            }
            tmp.push_back(minn);
        }

        return tmp[n - 1];
    }
};

作者：zhenying
链接：https://leetcode-cn.com/problems/super-ugly-number/solution/cpp-44ms-9474-by-xiwuxuewei/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
