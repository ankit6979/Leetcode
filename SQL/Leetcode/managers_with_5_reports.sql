# Write your MySQL query statement below
SELECT emp.name
FROM (
    SELECT managerId, count(*) AS reportee_cnt
    FROM Employee
    GROUP BY managerId
    HAVING reportee_cnt >= 5 AND managerId IS NOT NULL
) AS reportee
JOIN Employee AS emp
ON emp.id = reportee.managerId

/*
Optimized
*/

SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING count(*) >= 5
)
