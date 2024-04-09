create table student( stud_id int primary key, name varchar(30), class varchar(20));
create table competition(c_no int primary key, c_name varchar(30), type varchar(20));
create table student_comp(stud_id int references student(stud_id) on delete cascade, c_no int references competition(c_no) on delete cascade, rank varchar(20), year int);
insert into student values(1,'xyz','5th');
insert into student values(2,'abc','6th');

insert into competition values(101,'pqr','outdoor');
insert into competition values(102,'cricket','outdoor');

insert into student_comp values(2,102,'1st', 2020);
insert into student_comp values(1,101,'2nd', 2021);

