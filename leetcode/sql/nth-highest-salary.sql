CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT 
BEGIN
SET N=N-1; -- to get the correct offset; as offset 0 is the first row  
RETURN
    (SELECT
         (SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT 1
          OFFSET N) AS getNthHighestSalary ); 
END