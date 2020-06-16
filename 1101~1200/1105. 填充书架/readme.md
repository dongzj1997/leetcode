# 1105. 填充书架

```c++
附近的家居城促销，你买回了一直心仪的可调节书架，打算把自己的书都整理到新的书架上。

你把要摆放的书 books 都整理好，叠成一摞：从上往下，第 i 本书的厚度为 books[i][0]，高度为 books[i][1]。

按顺序 将这些书摆放到总宽度为 shelf_width 的书架上。

先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelf_width），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。

需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。 例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。

每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。

以这种方式布置书架，返回书架整体可能的最小高度。

 

示例：



输入：books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
输出：6
解释：
3 层书架的高度和为 1 + 3 + 2 = 6 。
第 2 本书不必放在第一层书架上。
 

提示：

1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/filling-bookcase-shelves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

挺好的一道dp，第一时间确实没想到。

开一个长度为len的数组，存放的是前i个元素可以累成的最小高度。

新进来一个元素，先让他另起一行，然后依次将他前面几个元素放到它后面（同时记录最大高度）

最后总的高度 = 前面的高度 + 后面的最大高度 ，此时计算期间的最小的实际高度即可。

```c++
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int len = books.size();
        
        vector<int> dp(len+1,INT_MAX);
        
        dp[0] = 0;
        for (int i=1; i<=len; ++i) {
            int sum = 0; 
            int height = 0;

            //尝试将前几个放到这一行
            for (int j=i; j>0; j--) {
               if (sum+books[j-1][0] <= shelf_width) {
                   sum += books[j-1][0];
                   height = max(height, books[j-1][1]);
                   dp[i] = min(dp[i], height+dp[j-1]);
               } else {
                   break;
               }
            }
        }
        return dp[len];
    }
};
```

---

