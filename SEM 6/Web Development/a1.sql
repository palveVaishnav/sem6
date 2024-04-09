--insert into movie values(2,'ved',2022);
--create table actor(actor_no int primary key, name varchar(30));
--insert into actor values(101,'akshay');
insert into actor values(102,'ritesh');
create table movie_actor(movie_no int references movie(movie_no) on delete cascade, actor_no int references actor(actor_no) on delete cascade, rate int);
insert into movie_actor values(2,101,40000);
insert into movie_actor values(2,102,50000);
