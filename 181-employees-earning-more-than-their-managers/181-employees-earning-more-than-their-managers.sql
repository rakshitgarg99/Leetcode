# Write your MySQL query statement below


select name as Employee from employee e where salary > (select salary from employee m where m.id=e.managerId);