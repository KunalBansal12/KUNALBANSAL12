# Write your MySQL query statement below
SELECT v.id FROM Weather as w
inner join
Weather as v ON DATEDIFF(v.recordDate, w.recordDate) = 1 WHERE v.temperature>w.temperature;