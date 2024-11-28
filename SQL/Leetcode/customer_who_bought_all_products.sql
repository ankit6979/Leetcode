# Write your MySQL query statement below
/* 1 */
select
    customer_id
from Customer
group by customer_id
having count(distinct product_key) = (
    select count(*) from Product
)

/* 2 */
WITH ProductCount AS (
    SELECT count(*) AS total_products
    FROM Product
)
SELECT
    customer_id
FROM Customer, ProductCount
GROUP BY customer_id
HAVING count(DISTINCT product_key) = total_products

/* 3 */

WITH DistinctProductCount AS (
    SELECT
        customer_id,
        COUNT(DISTINCT product_key) AS distinct_count
    FROM Customer
    GROUP BY customer_id
),
ProductCount AS (
    SELECT COUNT(*) AS total_products FROM Product
)
SELECT
    customer_id
FROM DistinctProductCount, ProductCount -- CROSS JOIN
WHERE distinct_count = total_products
