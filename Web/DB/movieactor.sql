DROP TABLE IF EXISTS movieactor;
DROP TABLE IF EXISTS movie;
DROP TABLE IF EXISTS actor;

CREATE TABLE movie(
	movie_no INT PRIMARY KEY,
	movie_name VARCHAR(10),
	r_year INT
);
CREATE TABLE actor(
	actor_no INT PRIMARY KEY,
	actor_name VARCHAR(20)
);

INSERT INTO movie(movie_no,movie_name,r_year)
VALUES 
(01,'Movie 1',2004),
(02,'Movie 2',2001),
(03,'Movie 3',2003),
(04,'Movie 5',2004),
(05,'Movie 6',2005),
(06,'Movie 7',2006);

INSERT INTO actor(actor_no,actor_name)
VALUES
(1,'Actor1'),
(2,'Actor2'),
(3,'Actor3');

CREATE TABLE movieActor(
	m_id INT REFERENCES movie(movie_no),
	a_id INT REFERENCES actor(actor_no)
);

INSERT INTO movieActor
VALUES
(01,1),
(02,1),
(03,2),
(04,2),
(05,3),
(06,3);
















