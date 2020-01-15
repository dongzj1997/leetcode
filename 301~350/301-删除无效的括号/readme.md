# 301. 删除无效的括号

```c++
删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。

说明: 输入可能包含了除 ( 和 ) 以外的字符。

示例 1:

输入: "()())()"
输出: ["()()()", "(())()"]
示例 2:

输入: "(a)())()"
输出: ["(a)()()", "(a())()"]
示例 3:

输入: ")("
输出: [""]

来源：力扣（LeetCode）
链接：https://dev.lingkou.xyz/problems/remove-invalid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法一，使用暴力的广度优先搜索算法

（需要存储已经判断过的字符串，防止重复，除此之外，还要用一个队列存储带搜索的可疑解，时间、空间复杂度都不是很好，但是理解简单）

用BFS，因为这样的话，对于一个初始s,遍历它，并减去一个不合理的符号，得到的第一层就是全是n-1长度的，当减去一些后得到一个合理的字符串时，停止剪。那么这个层数就是减去的个数也是最小减去个数得到的结果。

当root层时s有长度n,则到第二层时，有c(n,n-1)个长度为n-1的子串，同时进行验证是时间为O(n-1)，因此第一层的时间复杂度为O(n-1)*c(n,n-1);同理第二层的时间复杂度为O(n-2)*c(n-1,n-2)。。。。

时间复杂度为 

T(n) = n x C(n, n) + (n-1) x C(n, n-1) + ... + 1 x C(n, 1) = n x 2^(n-1).


```c++
class Solution {
public:
	bool isValid(string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				count++;
			else if (s[i] == ')')
				count--;
			if (count < 0)
				return false;
		}
		return count==0;
	}

	vector<string> removeInvalidParentheses(string s) {
		bool hasans = false;//是否找到一个最优解的标志变量
		int strlen = 0;
		unordered_set<string> uset;  //存储已经判断过的字符串，防止重复
		vector<string>res;   //存储结果
		queue<string> q; //广度优先搜索的搜索域
		q.push(s);
		uset.insert(s);
		while (!q.empty()) {
			string ts = q.front();
			q.pop();
			if (hasans) {
				if (ts.size() < strlen)
					return res;
			}
			if (isValid(ts)) {
				res.push_back(ts);
				hasans = true; //说明找到至少一个最优解
				strlen = ts.size();
			}

			if (hasans) continue; //找到一个最优解以后，不再往队列中新加可疑解，而是搜索完相同步数的所有可疑解

			for (int i = 0; i < ts.size(); i++) {
				if (ts[i] == '(' || ts[i] == ')') {
					string strs = ts.substr(0, i) + ts.substr(i + 1);
					if (uset.find(strs) == uset.end()) {
						uset.insert(strs);
						q.push(strs);
					}

				}
					
			}
		}
		return res;
	}
};
```

---

## 方法二，使用DFS

原链接在[这里](https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shen-du-you-xian-sou-suo-jie-ti-by-shaft/)

此题与之前的生成括号方式互为相反的过程，生成时我们需要记录已加入的左边和右边括号个数，删除时我们也需要。
在此题中，解题步骤如下：

我们需要先找出不合法的左括号个数和右括号个数

利用dfs不断删除"（"或者"）"，直到不合法个数为0

检验删除后的括号串是否合法。

```c++
class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        // 寻找不合法半边括号的个数
        int left=0;
        int right=0;
        for(char i:s){
            if(i=='('){
                left++;
            }
            if(i==')'){
                if(left>0)left--;
                else right++;
            }
        }
        // 深度优先遍历，寻找题解
        // left与right为需要删除的数量
        dfs(s, 0, left, right); //第二个参数为开始搜索的位置
        
        return ans;
    }
    void dfs(string s, int st, int l, int r){
        if(l==0&&r==0){
            if(check(s)){
                ans.push_back(s);
            }
            return;
        }
        for(int i=st;i<s.size();i++){
             // 去重
            if(i-1>=st&&s[i]==s[i-1])continue;
            if(l>0&&s[i]=='('){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l-1, r);
            }
            if(r>0&&s[i]==')'){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l, r-1);
            }
        }
    }
    // 检验合法性
    bool check(string s){
        int cnt=0;
        for(char i:s){
            if(i=='('){
                cnt++;
            }
            if(i==')'){
                cnt--;
                if(cnt<0)return false;
            }
        }
        return cnt==0;
    }
};
/*
作者：shaft
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shen-du-you-xian-sou-suo-jie-ti-by-shaft/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```