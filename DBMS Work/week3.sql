--Insert 10 records into students. 
--update marks for a given  student
--Delete students with marks <30
use Student_Db;
use Student_Db;
CREATE TABLE students 
(id INT, name VARCHAR(20), age INT, marks INT);
SELECT * FROM students;
ALTER TABLE students ADD grade VARCHAR(5);


--Insert 10 Records__
INSERT INTO students	
(id, name, age, marks, grade)
VALUES
(3,'Shahid',12,45,'C'),
(4,'Maroof',18,25,'F'),
(5,'Sahil',21,15,'F'),
(6,'Shakir',20,90,'A+'),
(7,'Javaid',10,75,'B'),
(8,'Shabir',21,50,'C'),
(9,'Jabbar',25,89,'A'),
(10,'Ismaeel',20,20,'F');

--Update Marks for a given stduent
UPDATE students
SET marks = 76 WHERE id = 8;

--Delete students with marks less than 30
DELETE FROM students WHERE marks < 30;

SELECT * FROM students;