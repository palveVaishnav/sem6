DROP TABLE IF EXISTS STUDENT;
DROP TABLE IF EXISTS COMP;

CREATE TABLE STUDENT(
	s_id INT PRIMARY KEY,
	s_name VARCHAR(10),
	s_class VARCHAR(10),
);

CREATE TABLE COMP(
	c_no INT PRIMARY KEY,
	c_name VARCHAR(10),
	c_type VARCHAR(10)
);

INSERT INTO STUDENT(s_id,s_name,s_class)
VALUES
(1,'name-1','10A'),
(2,'name-2','10B'),
(3,'name-3','11A'),
(4,'name-4','12B');


INSERT INTO COMP(c_no,c_name,c_type)
VALUES
()




