# 180. 连续出现的数字

```c++
编写一个 SQL 查询，查找所有至少连续出现三次的数字。

+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
例如，给定上面的 Logs 表， 1 是唯一连续出现至少三次的数字。

+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/consecutive-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```sql
select distinct a.Num ConsecutiveNums 
from Logs a,Logs b,Logs c 
where 
a.Num=b.Num 
and b.Num=c.Num 
and a.Id+1=b.Id 
and b.Id+1=c.Id 
```

---

上述为最笨的写法

---

评论区有大神写法(利用用户变量实现对连续出现的值进行计数)：

```sql
select distinct Num as ConsecutiveNums
from (
  select Num, 
    case 
      when @prev = Num then @count := @count + 1
      when (@prev := Num) is not null then @count := 1
    end as CNT
  from Logs, (select @prev := null,@count := null) as t
) as temp
where temp.CNT >= 3
```

与自关联或自连接相比，这种方法的效率更高，不受Logs表中的Id是否连续的限制，而且可以任意设定某个值连续出现的次数。
