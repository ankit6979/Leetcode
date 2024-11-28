# Write your MySQL query statement below
with cte as(
    select
        num
    from mynumbers
    group by num
    having count(num) = 1
    order by num desc
    limit 1
)
select * from cte
union all
select null as num from mynumbers limit 1

/*
optimized
*/

(
    SELECT num
    FROM mynumbers
    GROUP BY num
    HAVING COUNT(num) = 1
    ORDER BY num DESC
    LIMIT 1
)
UNION ALL
(
    SELECT NULL AS num
    WHERE NOT EXISTS (
        SELECT 1
        FROM mynumbers
        GROUP BY num
        HAVING COUNT(num) = 1
    )
);
