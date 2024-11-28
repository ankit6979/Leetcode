# Write your MySQL query statement below
with total_sales as (
    select p.product_id, p.price, coalesce(u.units, 0) as units_sold
    from prices as p left join unitssold as u
    on u.product_id = p.product_id and u.purchase_date >= p.start_date and u.purchase_date <= p.end_date
)
select product_id, coalesce(round(sum(price*units_sold)/sum(units_sold),2), 0) as average_price
from total_sales
group by product_id

/*
Optimized query
*/
-- Optimized Query
WITH total_sales AS (
    SELECT 
        p.product_id, 
        p.price, 
        COALESCE(u.units, 0) AS units_sold
    FROM 
        prices AS p
    LEFT JOIN 
        unitssold AS u
    ON 
        u.product_id = p.product_id
        AND u.purchase_date BETWEEN p.start_date AND p.end_date
)
SELECT 
    product_id, 
    COALESCE(ROUND(SUM(price * units_sold) / NULLIF(SUM(units_sold), 0), 2), 0) AS average_price
FROM 
    total_sales
GROUP BY 
    product_id;
