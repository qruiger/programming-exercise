SELECT DISTINCT a.num AS ConsecutiveNums
FROM logs a,
     logs b,
     logs c
WHERE a.id+1=b.id
    AND b.id+1=c.id
    AND a.num=b.num
    AND b.num=c.num