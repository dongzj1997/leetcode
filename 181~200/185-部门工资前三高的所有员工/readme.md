# 185-部门工资前三高的所有员工

```c++
Employee 表包含所有员工信息，每个员工有其对应的工号 Id，姓名 Name，工资 Salary 和部门编号 DepartmentId 。

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 85000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
| 7  | Will  | 70000  | 1            |
+----+-------+--------+--------------+
Department 表包含公司所有部门的信息。

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
编写一个 SQL 查询，找出每个部门获得前三高工资的所有员工。例如，根据上述给定的表，查询结果应返回：

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Randy    | 85000  |
| IT         | Joe      | 85000  |
| IT         | Will     | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
解释：

IT 部门中，Max 获得了最高的工资，Randy 和 Joe 都拿到了第二高的工资，Will 的工资排第三。销售部门（Sales）只有两名员工，Henry 的工资最高，Sam 的工资排第二。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/department-top-three-salaries
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```sql
/* Write your T-SQL query statement below */
select d.Name as Department,e.Name as Employee,e.Salary as Salary
from Employee as e left join Department as d 
on e.DepartmentId = d.Id
where e.Id in
(
    select e1.Id
    from Employee as e1 left join Employee as e2
    on e1.DepartmentId = e2.DepartmentId and e1.Salary < e2.Salary
    group by e1.Id
    having count(distinct e2.Salary) <= 2
)
and e.DepartmentId in (select Id from Department)

```

---

对于分组内取前几名的问题，可以先先对表做自身的链接，然后根据第一个id做group by然后用having count()来筛选，比如这题，找每个部门的工资前三名，那么先在子查询中用Employee和自己做连接，连接条件是【部门相同但是工资比我高】，那么接下来按照having count(Salary) <= 2来筛选的原理是：如果【跟我一个部门而且工资比我高的人数】不超过2个，那么我一定是部门工资前三，这样内层查询可以查询出所有符合要求的员工ID。
