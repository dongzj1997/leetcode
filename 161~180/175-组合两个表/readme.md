# 175. 组合两个表

```c++
SQL架构
表1: Person

+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId 是上表主键
表2: Address

+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId 是上表主键
 

编写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：

 

FirstName, LastName, City, State
```

---

## 解题：数据库初探

题目要求 **person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：**

所以使用 左结合 `表1 left join 表2 on 条件` ,这样的话它不管on中的条件是否为真，都会返回左边表中的记录。

---

```sql
/* Write your T-SQL query statement below */
select Person.FirstName, Person.LastName, Address.City, Address.State
from 
Person left join Address
on 
Person.PersonId = Address.PersonId
;
```
