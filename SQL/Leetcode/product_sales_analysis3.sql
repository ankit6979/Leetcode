# Write your MySQL query statement below
WITH SalesYears AS (
    SELECT
        product_id,
        year,
        quantity,
        price,
        RANK() over(partition by product_id order by year) as year_number
    FROM Sales
)
SELECT
    product_id,
        year AS first_year,
        quantity,
        price
FROM SalesYears
WHERE year_number = 1