# 182. 查找重复的电子邮箱

```c++
SQL架构
编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。

示例：

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
根据以上输入，你的查询应返回以下结果：

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
说明：所有电子邮箱都是小写字母。
```

---

```sql
# Write your MySQL query statement below
select distinct a.Email 
from 
Person a, Person b 
where 
a.Email = b.Email and a.Id != b.Id 
```

---

sql 所写即所思
