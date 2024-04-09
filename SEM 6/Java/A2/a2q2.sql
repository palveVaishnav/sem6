create table teacher(teacher_id int primary key, teacher_name varchar(30));
CREATE TABLE  workload(subject_code int primary key,subject varchar(30), date text, time text, class varchar(20), teacher_id int references teacher(teacher_id) on delete cascade);
insert into teacher values(1,'manohar');
insert into teacher values(2,'manu');
insert into workload values(101,'os','2000-12-3','09:10', '5th', 1);

