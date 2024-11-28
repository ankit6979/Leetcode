# Write your MySQL query statement below
SELECT emp.NAME, bns.bonus
FROM Employee AS emp LEFT JOIN Bonus AS bns
ON emp.empId = bns.empId
WHERE bns.bonus IS NULL OR bns.bonus < 1000

-- Optimizations
-- Use ISNULL in the WHERE Clause: If the goal is to filter out employees who
-- either have no bonus or have a bonus less than 1000, using the ISNULL function
-- can be more explicit and potentially optimize performance on certain SQL engines.
-- This way, you're handling the NULL check within the function rather than using a
-- direct OR statement, which can be more efficient.