# Write your MySQL query statement below

Select DISTINCT author_id as id  from Views
where viewer_id=author_id
ORDER BY author_id ASC ;