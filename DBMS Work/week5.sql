--Find average marks of students
--Count number of students in each grade
--Find maximum marks scored
USE Student_Db;

SELECT * FROM students;
--Find average marks of students
SELECT AVG(marks) AS 'AverageMArks' FROM students;

--Count number of students in each grade
SELECT grade, COUNT(*) AS 'No_Of_Stu.' FROM students GROUP BY  grade;

SELECT  MAX(marks) AS 'Max Marks '  FROM students ;
