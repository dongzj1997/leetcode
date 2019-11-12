# 178. 分数排名

```c++
编写一个 SQL 查询来实现分数排名。如果两个分数相同，则两个分数排名（Rank）相同。请注意，平分后的下一个名次应该是下一个连续的整数值。换句话说，名次之间不应该有“间隔”。

+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
例如，根据上述给定的 Scores 表，你的查询应该返回（按分数从高到低排列）：

+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rank-scores
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```sql
# Write your MySQL query statement below
select 
a.Score as score , 
(select count(distinct b.Score) 
from Scores b where b.Score >=a.Score) as rank
from Scores a order by Score DESC;

```

---

## 解题

参考了：[这里](https://leetcode-cn.com/problems/rank-scores/solution/mysqlbi-jiao-hao-li-jie-de-yi-chong-xie-fa-by-zaza/)

对于a表中的每一个分数score，找出b表中有多少个大于或等于该分数的不同的分数，然后按降序排列
