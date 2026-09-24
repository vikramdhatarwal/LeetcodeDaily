# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary
from Department d
left join Employee e
on d.id= e.departmentId
where e.salary=(
    select max(e1.salary)
    from Employee as e1
    where e1.departmentId= d.id
)