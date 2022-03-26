CREATE TABLE employee (
  empid VARCHAR(255),
  emp_name VARCHAR(255),
  dob DATE NULL,
  doj DATE NULL,
  gender CHAR,
  salary NUMBER,
  designation VARCHAR(255),
  project_domain VARCHAR(255),
  mobile_no NUMBER,
  dept NUMBER);
  
ALTER TABLE employee ADD CONSTRAINT empid_primary_key PRIMARY KEY(empid);

ALTER TABLE employee ADD CONSTRAINT mobile_no_unique UNIQUE(mobile_no);
ALTER TABLE employee ADD CONSTRAINT mobile_no_check CHECK(REGEXP_LIKE(mobile_no, '^\d{10}'));

ALTER TABLE employee ADD CONSTRAINT salary_min_check CHECK(salary >= 10000);
ALTER TABLE employee ADD CONSTRAINT salary_max_check CHECK(salary <= 60000);

ALTER TABLE employee ADD CONSTRAINT gender_check_c CHECK(gender IN ('M', 'F'));

--ALTER TABLE employee ADD CONSTRAINT age_check CHECK(TIMESTAMPDIFF(YEAR,dob, doj) >= 25);
--ALTER TABLE employee DROP CONSTRAINT age_check;

ALTER TABLE employee ADD CONSTRAINT emp_name_check CHECK(REGEXP_LIKE(emp_name, '\D+') AND LENGTH(emp_name) > 0);

ALTER TABLE employee ADD CONSTRAINT project_domain_check CHECK(REGEXP_LIKE(project_domain, '\D+') AND LENGTH(project_domain) > 0);

CREATE TABLE department (
	dept_id NUMBER,
	dept_name VARCHAR(30),
	dept_loc VARCHAR(30));

ALTER TABLE department ADD CONSTRAINT dept_id_primary_key PRIMARY KEY(dept_id);	

INSERT INTO department VALUES (1, 'Administration', 'Houston');
INSERT INTO department VALUES (2, 'Sales', 'Bellaire');
INSERT INTO department VALUES (3, 'Finance', 'Houston');
INSERT INTO department VALUES (4, 'Information Technology', 'Sugarland');

ALTER TABLE employee
ADD CONSTRAINT dept_foreign
  FOREIGN KEY(dept)
  REFERENCES department(dept_id);

--1
SELECT empid, emp_name, salary FROM employee WHERE project_domain = 'Banking';

--2
SELECT designation, COUNT(*) FROM employee WHERE designation = 'Programmer' GROUP BY designation;

--3
SELECT project_domain, COUNT(*) FROM employee GROUP BY project_domain;

--4
SELECT dept_name, dept_loc, emp_count FROM department D INNER JOIN (SELECT dept, COUNT(*) AS emp_count FROM employee GROUP BY dept) E on D.dept_id = E.dept;

--5
SELECT dept_name, dept_loc, emp_count FROM department D INNER JOIN (SELECT dept, COUNT(*) AS emp_count FROM employee GROUP BY dept) E on D.dept_id = E.dept WHERE dept_loc = 'Bellaire';

--6
SELECT empid, emp_name, salary, salary + 0.05 * salary as Increased_Salary FROM employee ORDER BY Increased_Salary;

--7
SELECT project_domain, COUNT(*) FROM employee WHERE project_domain = 'MobileApp' GROUP BY project_domain;

--8
SELECT * FROM employee WHERE dept = (SELECT dept_id FROM department WHERE dept_loc = 'Bellaire');

--9
SELECT empid, emp_name, dob, doj, gender, salary, E.project_domain FROM employee E INNER JOIN (SELECT project_domain, max(salary) as msal FROM employee WHERE project_domain IN (SELECT project_domain FROM employee GROUP BY project_domain HAVING COUNT(*) > 2) GROUP BY project_domain) D ON e.project_domain = D.project_domain WHERE E.salary = D.msal;

--10
-- SELECT EXTRACT(month FROM doj) as mon, COUNT(*) FROM employee E WHERE designation = 'Programmer' GROUP BY EXTRACT(month FROM doj) ORDER BY mon HAVING COUNT(*) = (SELECT MAX(pcount) FROM (SELECT EXTRACT(month FROM doj) as mon, COUNT(*) as pcount FROM employee E WHERE designation = 'Programmer' GROUP BY EXTRACT(month FROM doj) ORDER BY mon) F);
-- SELECT EXTRACT(month FROM doj) as mon, COUNT(*) as pcount FROM employee E WHERE designation = 'Programmer' GROUP BY EXTRACT(month FROM doj) ORDER BY mon;

--11
SELECT * FROM employee ORDER BY emp_name, designation, project_domain;

--12
SELECT project_domain, AVG(salary) as avg_salary, SUM(salary) as salary_sum FROM employee GROUP BY project_domain;

--13
SELECT dept_name FROM department D INNER JOIN employee E ON D.dept_id = E.dept WHERE E.designation = 'Project Leader';

--14
SELECT * FROM employee WHERE EXTRACT(month FROM dob) = 4;

--15
SELECT * FROM (SELECT * FROM employee ORDER BY dob ASC) WHERE ROWNUM < 2;

--17
SELECT emp_name FROM employee E INNER JOIN department D ON D.dept_id = E.dept WHERE D.dept_name = 'Sales' AND (E.salary BETWEEN 10000 AND 25000);

--18
SELECT E.emp_name, TRUNC(months_between(SYSDATE, E.dob) / 12) as age FROM (SELECT emp_name, dob FROM employee ORDER BY dob ASC) E WHERE ROWNUM < 2;

--19
SELECT * FROM employee WHERE mobile_no IS NULL;

--20
SELECT gender, AVG(TRUNC(months_between(SYSDATE, dob) / 12)) FROM employee GROUP BY gender;

--21
SELECT * FROM employee WHERE EXTRACT(month FROM dob) = EXTRACT(month FROM SYSDATE);

--22
SELECT * FROM employee WHERE EXTRACT(year FROM doj) < 1991 AND designation IN ('System Analyst', 'Project Leader');

--23
SELECT * FROM employee WHERE TRUNC((SYSDATE - doj)/ 365.25) > 10 AND gender = 'F';

--24
SELECT * FROM employee WHERE EXTRACT(month FROM dob) IN (10, 3);

--25
SELECT emp_name, mobile_no, D.dept_loc, dob FROM employee E INNER JOIN department D ON E.dept = D.dept_id ORDER BY TRUNC(months_between(SYSDATE, E.dob) / 12) DESC;

--26.
SELECT MAX(salary) AS "Max", MIN(salary) AS "Min", AVG(salary) AS "Average" FROM Employee WHERE salary > 10000;

--27.
SELECT MAX(salary) - MIN(salary) AS "Difference in Salary" FROM Employee;

--28.
SELECT emp_name FROM Employee WHERE LENGTH(emp_name) <= 5;

--29.
SELECT COUNT(DISTINCT project_domain) AS "Number of Projects" FROM Employee;

--30.
SELECT project_domain FROM Employee GROUP BY project_domain HAVING count(empid) = (SELECT MIN(COUNT(empid)) FROM Employee GROUP BY project_domain);

--31.
SELECT emp_name FROM Employee WHERE (dob = (SELECT MAX(dob) FROM Employee WHERE Gender = 'M' AND EXTRACT(YEAR FROM dob) = 66)) OR (dob = (SELECT MIN(dob) FROM Employee WHERE Gender = 'F' AND EXTRACT(YEAR FROM dob) = 66));

--32.
SELECT to_char(to_date(EXTRACT(YEAR FROM dob), 'RR'), 'YYYY') AS "Year with Highest Births" FROM Employee WHERE ROWNUM = 1 GROUP BY EXTRACT(YEAR FROM dob) ORDER BY COUNT(*) DESC;

--33.
SELECT EXTRACT(MONTH FROM dob) AS "Month with Highest Births" FROM Employee WHERE ROWNUM = 1 GROUP BY EXTRACT(MONTH FROM dob) ORDER BY COUNT(*) DESC;

--34.
SELECT emp_name FROM Employee WHERE salary < (SELECT AVG(salary) FROM Employee WHERE Gender = 'F');

--35.
SELECT emp_name FROM Employee WHERE salary > (SELECT MAX(salary) FROM Employee WHERE Gender = 'M');

--36.
SELECT * FROM Employee E1, Employee E2 WHERE E1.empid <> E2.empid AND E1.salary = E2.salary;

--37.
SELECT MIN(salary) AS "Second Highest Salary" FROM (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC) WHERE ROWNUM < 3;

--38.
SELECT emp_name FROM Employee WHERE salary > (SELECT MAX(AVG(salary)) FROM Employee GROUP BY dept);

--39.
SELECT Department.dept_name AS "Department", SUM(Employee.salary) AS "Sum of Programmers Salary" FROM Employee, Department WHERE Employee.dept = Department.dept_id AND Employee.designation = 'Programmer' GROUP BY Department.dept_name;

--40.
SELECT emp_name FROM Employee E JOIN Department D ON E.dept = D.dept_id WHERE d.dept_name = 'Sales';

--42.
SELECT * FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id WHERE dept_NAME = 'IT';

--43.
SELECT emp_name FROM Employee WHERE salary < (SELECT AVG(salary) FROM Employee WHERE designation = 'Developer');

--44.
SELECT dept_name FROM (SELECT D.dept_name, AVG(salary) FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id WHERE designation = 'Programmer' GROUP BY D.dept_name ORDER BY AVG(salary) DESC) WHERE ROWNUM < 2;

--45.
SELECT * FROM Department WHERE dept_name IN (SELECT dept_name FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id GROUP BY dept_name HAVING COUNT(empid) > 2);

--46.
SELECT emp_name FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id WHERE (dept_name = 'IT' OR dept_name = 'Sales') AND designation = 'Programmer';

--47.
SELECT dept_name, COUNT(DISTINCT project_domain) AS "Number of Projects" FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id GROUP BY dept_name;

--50.
SELECT * FROM Employee WHERE dept = (SELECT dept FROM Employee WHERE empid = 'PSG103');

--51.
SELECT emp_name, salary FROM Employee WHERE designation = 'Programmer' AND salary > (SELECT AVG(salary) FROM Employee GROUP BY designation HAVING designation = 'Developer');

--52.
SELECT dept_name FROM Employee E INNER JOIN Department D ON E.dept = D.dept_id WHERE E.designation <> 'Programmer' GROUP BY D.dept_name;

--IV
--a
DELETE FROM Employee WHERE project_domain = 'Finance';

--b
UPDATE Employee SET designation = 'AppProgrammer' WHERE project_domain = 'MobileApp' AND designation = 'Programmer';


