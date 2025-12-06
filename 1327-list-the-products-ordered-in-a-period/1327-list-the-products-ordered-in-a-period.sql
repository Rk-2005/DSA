# Write your MySQL query statement below

select p.product_name ,SUM(od.unit) AS unit
from Products p
join Orders od on p.product_id=od.product_id  
where DATE_FORMAT(od.order_date,'%Y')="2020" and DATE_FORMAT(od.order_date,'%m')="02"
group by p.product_name 
having sum(od.unit)>=100;
