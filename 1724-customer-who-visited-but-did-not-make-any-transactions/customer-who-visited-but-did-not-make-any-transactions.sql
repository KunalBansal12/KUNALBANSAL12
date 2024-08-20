# Write your MySQL query statement below
SELECT v.customer_id as customer_id,COUNT(v.customer_id) as count_no_trans FROM Visits as v
left join
Transactions as t using(visit_id) 
WHERE transaction_id IS NULL 
GROUP BY v.customer_id 
ORDER BY v.customer_id;