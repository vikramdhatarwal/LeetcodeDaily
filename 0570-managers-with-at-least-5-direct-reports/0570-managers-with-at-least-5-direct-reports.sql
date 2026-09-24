# Write your MySQL query statement below
select e1.name 
from Employee as e1
where 5<=(
    select count(*)
    from Employee as e2 
    where e1.id= e2.managerId
)