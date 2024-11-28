# Write your MySQL query statement below
with salary_rank as (
    select
        salary,
        dense_rank() over(order by salary desc) as rnk
    from
    Employee
)
(
    select
        salary as SecondHighestSalary
    from salary_rank
    where rnk = 2
    limit 1
)
union all
(
    select null as SecondHighestSalary
    where not exists (
        select
            salary as SecondHighestSalary
        from salary_rank
        where rnk = 2
    )
)

/*
Optimized
*/
# Write your MySQL query statement below
with salary_rank as (
    select
        salary,
        dense_rank() over(order by salary desc) as rnk
    from
    Employee
)
(
    select
        max(salary) as SecondHighestSalary
    from salary_rank
    where rnk = 2
)