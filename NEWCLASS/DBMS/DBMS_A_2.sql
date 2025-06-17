-- Create DEPT table
CREATE TABLE DEPT (
    Dno NUMBER(2) PRIMARY KEY,
    Dname VARCHAR2(10) NOT NULL
);

-- Create EMP table
CREATE TABLE EMP (
    Eno CHAR(2) PRIMARY KEY,
    Ename VARCHAR2(10) NOT NULL,
    City VARCHAR2(10),
    Salary NUMBER(6),
    Dno NUMBER(2),
    Join_Date DATE,
    CONSTRAINT eno_format CHECK (Eno LIKE 'E%'),
    CONSTRAINT city_name CHECK (City IN ('Chennai', 'Mumbai', 'Delhi', 'Kolkata')),
    CONSTRAINT salary_limit CHECK (Salary > 5000),
    FOREIGN KEY (Dno) REFERENCES DEPT(Dno)
);

-- Create PROJECT table
CREATE TABLE PROJECT (
    Pro CHAR(2),
    Eno CHAR(2),
    PRIMARY KEY (Pro, Eno),
    CONSTRAINT pro_format CHECK (Pro LIKE 'P%'),
    FOREIGN KEY (Eno) REFERENCES EMP(Eno)
);

-- Insert data into DEPT
INSERT INTO DEPT (Dno, Dname) VALUES (1, 'Research');
INSERT INTO DEPT (Dno, Dname) VALUES (2, 'Finance');

-- Insert data into EMP
INSERT INTO EMP VALUES ('E1', 'Ashim', 'Kolkata', 10000, 1, '01-Jun-2022');
INSERT INTO EMP VALUES ('E2', 'Kamal', 'Mumbai', 18000, 2, '05-Jul-2022');
INSERT INTO EMP VALUES ('E3', 'Tamal', 'Chennai', 7000, 1, '07-Jun-2019');
INSERT INTO EMP VALUES ('E4', 'Asha', 'Kolkata', 8000, 2, '08-Dec-2018');
INSERT INTO EMP VALUES ('E5', 'Timir', 'Delhi', 7000, 1, '12-Mar-2017');

-- Insert data into PROJECT
INSERT INTO PROJECT VALUES ('P1', 'E1');
INSERT INTO PROJECT VALUES ('P2', 'E3');
INSERT INTO PROJECT VALUES ('P1', 'E5');
INSERT INTO PROJECT VALUES ('P2', 'E1');

DESCRIBE DEPT;

DESCRIBE EMP;

DESCRIBE PROJECT;

SELECT *
FROM DEPT;

SELECT *
FROM EMP;

SELECT *
FROM PROJECT;

-- 1
SELECT *
FROM EMP
WHERE ENAME LIKE '_a%';

-- 2
SELECT ENAME
FROM EMP
WHERE EXTRACT(MONTH FROM Join_Date) = 6;

-- 3
SELECT *
FROM EMP
WHERE ENAME NOT LIKE 'T%';

-- 4
SELECT ENAME
FROM EMP
WHERE CITY IN ('Chennai', 'Delhi', 'Mumbai');

-- 5
SELECT *
FROM EMP
WHERE SALARY BETWEEN 7000 AND 18000;

-- 6
SELECT DISTINCT CITY
FROM EMP;

-- 7
SELECT ENAME, SALARY
FROM EMP
ORDER BY SALARY DESC;

-- 8
SELECT ENAME
FROM EMP
ORDER BY ENAME;

-- 9
SELECT *
FROM EMP
WHERE EXTRACT(YEAR FROM Join_Date) = 2022;

-- 10
SELECT AVG(SALARY)
FROM EMP;

-- 11
SELECT MAX(SALARY) - MIN(SALARY)
FROM EMP;

-- 12
SELECT COUNT(ENO)
FROM EMP;

-- 13
SELECT TO_CHAR(Join_Date, 'DD/MM/YYYY') AS Joining_Date
FROM EMP;

-- 14
SELECT ENAME
FROM EMP
WHERE ENAME LIKE '____';

-- 15
DESC EMP;

-- 16
SELECT 
    Ename,
    Salary,
    Salary * 0.5 AS HRA,
    Salary * 0.3 AS DA,
    Salary + (Salary * 0.5) + (Salary * 0.3) AS Gross_Salary
FROM EMP;

-- 17
SELECT ENAME
FROM EMP
WHERE ENAME NOT IN 'Tamal' AND SALARY IN (
    SELECT SALARY
    FROM EMP
    WHERE ENAME IN 'Tamal'
);

-- 18
SELECT ENO, ENAME, SALARY
FROM EMP
WHERE SALARY IN (
    SELECT MIN(SALARY)
    FROM EMP
);