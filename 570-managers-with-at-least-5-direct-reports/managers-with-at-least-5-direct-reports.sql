# Write your MySQL query statement below
SELECT name FROM Employee WHERE id IN (SELECT managerId FROM Employee e2 WHERE managerId IS NOT NULL GROUP BY managerId HAVING COUNT(managerId)>=5);