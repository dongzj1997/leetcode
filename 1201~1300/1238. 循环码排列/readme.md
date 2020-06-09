# 1238. 循环码排列

```c++
给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：

p[0] = start
p[i] 和 p[i+1] 的二进制表示形式只有一位不同
p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
 

示例 1：

输入：n = 2, start = 3
输出：[3,2,0,1]
解释：这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
示例 2：

输出：n = 3, start = 2
输出：[2,6,7,5,4,0,1,3]
解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-permutation-in-binary-representation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先生成格雷编码（no.89），然后旋转数组(no.189)。

```c++
//格雷编码
class Solution {
    public List<Integer> grayCode(int n) {
        /**
        关键是搞清楚格雷编码的生成过程, G(i) = i ^ (i/2);
        如 n = 3: 
        G(0) = 000, 
        G(1) = 1 ^ 0 = 001 ^ 000 = 001
        G(2) = 2 ^ 1 = 010 ^ 001 = 011 
        G(3) = 3 ^ 1 = 011 ^ 001 = 010
        G(4) = 4 ^ 2 = 100 ^ 010 = 110
        G(5) = 5 ^ 2 = 101 ^ 010 = 111
        G(6) = 6 ^ 3 = 110 ^ 011 = 101
        G(7) = 7 ^ 3 = 111 ^ 011 = 100
        **/
        List<Integer> ret = new ArrayList<>();
        for(int i = 0; i < 1<<n; ++i)
            ret.add(i ^ i>>1);
        return ret;
    }
}
```

```c++
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>  ans;
        for(int i=0;i < 1<<n;i++)
            ans.push_back(i^i>>1);
        int k;
        for(int i=0;i<ans.size();i++)
            if(ans[i]==start) k=i;
       
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+ans.size()-k);
        reverse(ans.begin()+ans.size()-k,ans.end());
        
            
        return ans;
    }
};
```

---



