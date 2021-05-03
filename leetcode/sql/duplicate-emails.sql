SELECT Email
FROM Person
GROUP BY Email
HAVING count(email)>1