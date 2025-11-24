--retrieve students with marks above 80.
-- List all students sorted by age.
-- Show distinct grades from students.
use Student_Db;

SELECT * FROM students;
--A. retrieve students with marks above 80.
SELECT * FROM students WHERE marks>80;

--B. List all students sorted by age.
SELECT * FROM students ORDER BY age DESC;

--C. Show distinct grades from students.
SELECT DISTINCT grade FROM students;
SELECT * FROM students;