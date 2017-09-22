SELECT
    DISTINCT a.Num AS ConsecutiveNums
FROM
    Logs AS a, Logs AS b, Logs AS c
WHERE
    a.Num = b.Num AND b.Num = c.Num AND
    a.Id = b.Id + 1 AND a.Id = c.Id + 2;