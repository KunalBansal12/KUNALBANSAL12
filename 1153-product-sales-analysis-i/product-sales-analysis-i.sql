# Write your MySQL query statement below
SELECT p.product_name,s.year,s.price FROM Sales as s
LEFT JOIN
Product as p using(product_id);