SELECT e1.Name AS Employee
FROM Employee e1,
              Employee e2
WHERE e2.id = e1.managerid
    AND e1.salary>e2.salary;