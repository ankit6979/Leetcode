WITH prevData AS (
    SELECT
    id,
    recordDate,
    temperature,
    LAG(temperature) over(ORDER BY recordDate) as prev_temp,
    LAG(recordDate) over(ORDER BY recordDate) as prev_date
    FROM Weather
)

SELECT id
FROM prevData
WHERE prev_temp IS NOT NULL AND temperature > prev_temp AND DATEDIFF(recordDate, prev_date) = 1

-- Optimizations
-- Remove CTE (Common Table Expression): Using a CTE (in this case, WITH prevData AS (...)) in MySQL can
-- sometimes result in unnecessary materialization of intermediate results, which could slow down performance.
-- Instead, incorporate the logic directly in the main query.

-- Optimize the LAG function's window ordering: If there is an index on recordDate, MySQL can more efficiently
-- perform the ordering operation required by the LAG function. Adding an INDEX(recordDate) may help if the
-- Weather table does not already have one.