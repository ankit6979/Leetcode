# Write your MySQL query statement below
with monthly_transaction as (
    select
        substring(trans_date, 1, 7) as month,
        country,
        amount,
        state,
        id
    from Transactions
)
select
    month,
    country,
    count(id) as trans_count,
    sum(case when state = 'approved' then 1 else 0 end) as approved_count,
    sum(amount) as trans_total_amount,
    sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from monthly_transaction
group by month, country

/* Optimized Code */

select
    LEFT(trans_date, 7) AS month,
    country,
    count(id) as trans_count,
    sum(case when state = 'approved' then 1 else 0 end) as approved_count,
    sum(amount) as trans_total_amount,
    sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from transactions
group by month, country
