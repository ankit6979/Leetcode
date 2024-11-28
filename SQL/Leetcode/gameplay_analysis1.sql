select
    player_id,
    min(event_date) as first_login
from activity
group by player_id

-- without groupby

select
    distinct player_id,
    first_value(event_date) over(partition by player_id order by event_date asc) as first_login
from activity