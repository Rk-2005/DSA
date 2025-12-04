# Write your MySQL query statement below


SELECT X x,Y y,Z z,(CASE WHEN (X+Y>Z AND (X+Z>Y) AND (Y+Z)>X) THEN "Yes" ELSE "No" END) as triangle 
from Triangle  