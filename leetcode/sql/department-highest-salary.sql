SELECT Department.Name AS Department,
       Employee.Name AS Employee,
       Salary
FROM Employee
JOIN Department ON Employee.DepartmentId=Department.Id
WHERE (Employee.DepartmentId,
       Salary) IN
        (SELECT DepartmentId,
                max(salary)
         FROM Employee
         GROUP BY DepartmentId)