# Write your MySQL query statement below
SELECT user_id, ROUND(sum(confirmed) / count(confirmed), 2) AS confirmation_rate
FROM (
    SELECT
    su.user_id,
    CASE
        WHEN conf.action = 'confirmed' THEN 1 ELSE 0
        END AS confirmed
    FROM Signups AS su
    LEFT JOIN Confirmations AS conf
    ON su.user_id = conf.user_id
) AS confirmed_user
GROUP BY user_id

/*
Without subquery
*/

SELECT
su.user_id,
ROUND(SUM(CASE WHEN conf.action = 'confirmed' THEN 1 ELSE 0 END) / COUNT(su.user_id), 2) AS confirmation_rate
FROM Signups AS su
LEFT JOIN Confirmations AS conf
ON su.user_id = conf.user_id
GROUP BY user_id

/*
Using If and subquery
*/

SELECT
su.user_id,
ROUND(AVG(IF(conf.action = 'confirmed', 1, 0)), 2) AS confirmation_rate
FROM Signups AS su
LEFT JOIN Confirmations AS conf
ON su.user_id = conf.user_id
GROUP BY user_id