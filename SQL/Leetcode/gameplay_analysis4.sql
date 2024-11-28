# Write your MySQL query statement below
with cte as (
    select
        *,
        lag(event_date) over(partition by player_id order by event_date) as prev_date,
        rank() over (partition by player_id order by event_date asc) as rnk
    from activity
)
select round(
    (
        select count(distinct player_id) from cte where datediff(event_date, prev_date)=1 and rnk = 2
    ) / 
    (
        select count(distinct player_id) from activity
    ), 2) as fraction