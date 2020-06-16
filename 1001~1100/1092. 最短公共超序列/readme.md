# 1092. 最短公共超序列

```c++
给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。

（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T 的子序列）

 

示例：

输入：str1 = "abac", str2 = "cab"
输出："cabac"
解释：
str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。
 

提示：

1 <= str1.length, str2.length <= 1000
str1 和 str2 都由小写英文字母组成。
通过次数1,235提交次数2,849

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-common-supersequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

一道很好的训练dp的题。

1. 先构造出原先字符串每种情况下，最短公共超序列的长度，存在dp数组中。复杂度o(n*m)

2. 根据dp数组，反推出我们需要的结果，（采取从后往前扫描的方式，如果扫描到的字符相等，则直接加，如果字符不等，则走最短公共超序列的长度**较短**的那一分支）。

3. 将第二部生成的结果逆序就是最终的结果。

注意生成的字符串不唯一，但是长度相同。

```c++
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        int dp[1001][1001] = {0};  // dp[i][j]表示str1[:i]和str2[:j]的SCS长度
        for(int i=0;i<=len1;i++)  dp[i][0] = i; //初始化
        for(int j=0;j<=len2;j++)  dp[0][j] = j; 


        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + 1; //和LCS唯一的不同之处
                }
            }
        }

        //知道每个段的长度以后，开始构造最短公共超序列（从后往前）
        string ans = "";
        int i = len1, j = len2;
        while(i >0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }else if(dp[i - 1][j] < dp[i][j - 1]){ // 使用dp[i - 1][j] 比较短，走这一分支
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }

        //将剩余的分支走完
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        //最后的结果要逆序
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
```

---

除此之外，还有另一种解法，先求出LCS二维数组，然后反推出LCS字符串，最后根据字符串求出最终的结果。

注意反推出LCS字符串的过程和第一种解法有点不同，因为要取最长的公共字符串，所以要走长度较长的分支。

从LCS构造SCS的方法也非常简单，直接比较字符世是否相等，然后向后推进即可。

代码和思路来源于@[fatk](https://leetcode-cn.com/problems/shortest-common-supersequence/solution/javascript-2chong-si-lu-qiu-scs-by-da-fei-kai/)

```javascript

var shortestCommonSupersequence = function (A, B) {
  const aLen = A.length, bLen = B.length

  // dp[i][j]表示A[:i]与B[:j]的LCS长度
  const dp = Array.from({ length: aLen + 1 }, () => Array.from({ length: bLen + 1 }, () => 0))
  // 迭代求LCS长度
  for (let i = 1; i <= aLen; ++i) {
    for (let j = 1; j <= bLen; ++j) {
      if (A[i - 1] === B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
      }
    }
  }

  // 反推出LCS
  const lcs = []
  let i = aLen, j = bLen
  while (i > 0 && j > 0) {
    if (A[i - 1] === B[j - 1]) { // 相等，取该字符
      lcs.push(A[i - 1])
      --i
      --j
    } else { // 不相等时，走更大的方向
      dp[i - 1][j] > dp[i][j - 1] ? --i : --j
    }
  }
  lcs.reverse()

  // 从LCS构造SCS
  let scs = ''
  i = j = 0
  for (const ch of lcs) {
    while (A[i] !== ch) scs += A[i++]
    while (B[j] !== ch) scs += B[j++]
    scs += ch
    ++i
    ++j
  }
  // A、B剩余的
  scs += A.slice(i) + B.slice(j)

  return scs
};

作者：FatK
链接：https://leetcode-cn.com/problems/shortest-common-supersequence/solution/javascript-2chong-si-lu-qiu-scs-by-da-fei-kai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```