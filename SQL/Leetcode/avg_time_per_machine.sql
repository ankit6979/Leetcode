# Write your MySQL query statement below
SELECT machine_id, ROUND((sum(end_timestamp) - sum(start_timestamp))/ count(*), 3) AS processing_time
FROM
    (
        SELECT
        machine_id,
        process_id,
        MAX(CASE WHEN activity_type = 'start' THEN timestamp end) AS start_timestamp,
        MAX(CASE WHEN activity_type = 'end' THEN timestamp end) AS end_timestamp
        FROM Activity
        GROUP BY machine_id, process_id
) AS processes
GROUP BY machine_id