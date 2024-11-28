# Write your MySQL query statement below
with delivery_rank as (
    select
        customer_id,
        order_date,
        customer_pref_delivery_date,
        rank() over (partition by customer_id order by order_date) as delivery
    from Delivery
)
select
round(((sum(case when order_date = customer_pref_delivery_date then 1 else 0 end))/ count(customer_id))*100, 2) as immediate_percentage
from delivery_rank
where delivery = 1