create database college
create table 
course
(
c_id int constraint pk primary key, 
c_name varchar(20), 
faculty varchar(30) not null,
)
create table 
student 
(
s_id int constraint pk1 primary key,
s_name varchar(30) not null, 
r_no int constraint u1 unique, 
reg_no int constraint u2 unique, 
c_id int constraint fk foreign key references course(c_id)
) 

insert into course 
values 
(101, 'Python', 'Dr. Burhan'),
(102, 'DBMS', 'Dr. Burhan'),
(103, 'DSA', 'Dr. Jameel'),
(104, 'DS', 'Dr. Jameel');

insert into student 
values 
(1, 'Shariq', 100,1000,101),
(2, 'Bilal', 101,1001,102),
(3, 'Javaid', 107,1002,103),
(4, 'Iqra', 102,1003,104);

select s_name 
from student where 
c_id = (
select c_id from course where c_name = 'Python'
)	--Sub Query
select * from course
select * from student  right join course on student.s_id = course.c_id

insert into student 
values 
(101, 'Shariq', 100,10001,1011),
(102, 'Bilal', 101,10012,1022),
(103, 'Javaid', 107,10023,1033),
(104, 'Iqra', 102,10034,1044);

select * from student  full join course on student.s_id = course.c_id
