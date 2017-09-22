SELECT
    c.Name AS Department,
    b.Name AS Employee,
    a.ms AS Salary
FROM
    (SELECT MAX(Salary) AS ms, DepartmentId AS di FROM Employee GROUP BY di) AS a
JOIN
    Employee AS b
ON
    a.ms = b.Salary AND
    a.di = b.DepartmentId
JOIN
    Department AS c
ON
    a.di = c.Id;