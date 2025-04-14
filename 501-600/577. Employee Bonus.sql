select e.name, b.bonus from employee e 
LEFT join bonus b using (empID) 
WHERE b.bonus < 1000 or b.bonus IS NULL ;
