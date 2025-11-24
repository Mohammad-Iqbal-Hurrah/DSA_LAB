--Create a students table with id, name,age, marks. Add a new column grade. Drop a temporary--
use Student_Db;
CREATE TABLE students 
(id INT, name VARCHAR(20), age INT, marks INT);
SELECT * FROM students;
ALTER TABLE students ADD grade INT;
DROP TABLE students;