# Write your MySQL query statement below


select e1.name
from Employee e1
LEFT join Employee e2 
on e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e2.managerId)>=5;