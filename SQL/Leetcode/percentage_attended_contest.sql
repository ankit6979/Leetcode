# Write your MySQL query statement below
select contest_id,
        round((sum(1)/(select count(user_id) from Users))*100, 2) as percentage
from Register
group by contest_id
order by percentage desc, contest_id asc


/*
    Optimized
*/
-- Inline is slower as here CTE is evaluated once and then it's cross joined effectively to populate it for each user
WITH TotalUsers AS (
    Select count(*) as total_users
    from users
)
SELECT 
  contest_id,
  ROUND(COUNT(DISTINCT user_id) * 100 / total_users, 2) AS percentage
FROM Register r cross join TotalUsers 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;