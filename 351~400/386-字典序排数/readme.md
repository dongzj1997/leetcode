# 386-字典序排数

```c++
给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographical-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

当你想到一个又快有好的算法，写完提交以后眼一看评论区发现一年前已经有人写了 ----leetcode的日常

```c++
class Solution {
public:
	vector<int> ans;
	int n = 0;
	vector<int> lexicalOrder(int n) {
		this->n = n;
		for (int i = 1; i < 10; i++) {
			helper(i);
		}
		return ans;
	}

	void helper(int x) {
		if (x > n)
			return;
		ans.push_back(x);
		for (int i = 0; i < 10; i++) {
			helper(10 * x + i);
		}
		return;
	}
};

```

---

> 来自评论区的循环版本

```c++
class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int> res(n);
        int cur=1;
        for(int i=0;i<n;i++){
            res[i]=cur;
            if(cur*10<=n){
                cur*=10;
            }else{
                if(cur>=n) cur/=10;
                cur+=1;
                while(cur%10==0) cur/=10;
            }
        }
        return res;
    }
};

```

