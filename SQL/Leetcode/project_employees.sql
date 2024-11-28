# Write your MySQL query statement below
select
prjt.project_id, ROUND(AVG(emp.experience_years),2) as average_years
from Project as prjt left join Employee as emp
on emp.employee_id = prjt.employee_id
group by prjt.project_id