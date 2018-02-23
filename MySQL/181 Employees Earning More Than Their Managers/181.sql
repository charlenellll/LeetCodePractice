# Write your MySQL query statement below

select e1.Name as Employee
from Employee e1, Employee e2
where e1.ManagerId = e2.Id and e1.Salary > e2.Salary

# Inner Join is a little bit slower

select e1.Name as Employee
from Employee e1
Inner join Employee e2
where e1.ManagerId = e2.Id and e1.Salary > e2.Salary