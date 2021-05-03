-- offset 1 diplays the second row, which will be
-- second highest as we've ordered salary descending
SELECT
    (SELECT DISTINCT Salary
     FROM Employee
     ORDER BY Salary DESC
     LIMIT 1
     OFFSET 1) AS SecondHighestSalary;

-- alternatively

SELECT ifnull(
                  (SELECT DISTINCT Salary
                   FROM Employee
                   ORDER BY Salary DESC
                   LIMIT 1
                   OFFSET 1) , NULL) AS SecondHighestSalary ;