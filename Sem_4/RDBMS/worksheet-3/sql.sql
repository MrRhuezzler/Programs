CREATE TABLE supplier (
  sno INTEGER PRIMARY KEY,
  sname VARCHAR(255) NOT NULL,
  status INTEGER,
  city VARCHAR(255),
  CONSTRAINT status_mod_check CHECK(MOD(status, 10) = 0),
  CONSTRAINT status_uplimit_check CHECK(status <= 50),
  CONSTRAINT sname_capitalize_check CHECK(INITCAP(sname) = sname),
  CONSTRAINT city_capitalize_check CHECK(INITCAP(city) = city)
);

CREATE TABLE part (
  pno INTEGER PRIMARY KEY,
  pname VARCHAR(255) NOT NULL,
  color VARCHAR(255),
  weight INTEGER,
  city VARCHAR(255),
  CONSTRAINT pname_capitalize_check CHECK(INITCAP(pname) = pname),
  CONSTRAINT pcolor_capitalize_check CHECK(INITCAP(color) = color),
  CONSTRAINT pcity_capitalize_check CHECK(INITCAP(city) = city)
);

CREATE TABLE shipment (
  sno INTEGER,
  pno INTEGER,
  qty INTEGER,
  price NUMBER(5, 5),
  FOREIGN KEY (sno) REFERENCES supplier(sno),
  FOREIGN KEY (pno) REFERENCES part(pno),
  CONSTRAINT price_check CHECK(qty < 1000),
  PRIMARY KEY(sno, pno)
);

--supplier
INSERT INTO supplier VALUES (1,'Smith',20,'London');
INSERT INTO supplier VALUES (2,'Jones',10,'Paris');
INSERT INTO supplier VALUES (3,'Blake',30,'Paris');
INSERT INTO supplier VALUES (4,'Clark',20,'London');
INSERT INTO supplier VALUES (5,'Adams',30,NULL);

--part
INSERT INTO part VALUES (1,'Nut','Red',12,'London');
INSERT INTO part VALUES (2,'Bolt','Green',17,'Paris');
INSERT INTO part VALUES (3,'Screw',NULL,17,'Rome');
INSERT INTO part VALUES (4,'Screw','Red',14,'London');
INSERT INTO part VALUES (5,'Cam','Blue',12,'Paris');
INSERT INTO part VALUES (6,'Cog','Red',19,'London');

--shipment
INSERT INTO shipment VALUES (1,1,300,0.005);
INSERT INTO shipment VALUES (1,2,200,0.009);
INSERT INTO shipment VALUES (1,3,400,0.004);
INSERT INTO shipment VALUES (1,4,200,0.009);
INSERT INTO shipment VALUES (1,5,100,0.01);
INSERT INTO shipment VALUES (1,6,100,0.01);
INSERT INTO shipment VALUES (2,1,300,0.006);
INSERT INTO shipment VALUES (2,2,400,0.004);
INSERT INTO shipment VALUES (3,2,200,0.009);
INSERT INTO shipment VALUES (3,3,300,NULL);
INSERT INTO shipment VALUES (4,2,200,0.008);
INSERT INTO shipment VALUES (4,3,null,null);
INSERT INTO shipment VALUES (4,4,300,0.006);
INSERT INTO shipment VALUES (4,5,400,0.003);

--1
SELECT p.* FROM part p INNER JOIN shipment s ON s.pno = p.pno WHERE s.sno = 2;

--2
SELECT DISTINCT p1.* FROM part p1, part p2 WHERE p1.pno != p2.pno AND p1.color = p2.color;

--3
SELECT DISTINCT p1.* FROM supplier p1, supplier p2 WHERE p1.sno != p2.sno AND p1.city = p2.city ORDER BY p1.city;

--4
SELECT * FROM supplier WHERE city != 'Paris';

--5
SELECT * FROM supplier WHERE sno = (SELECT sno FROM shipment GROUP BY sno HAVING COUNT(*) = (SELECT COUNT(*) FROM part));

--6
SELECT * FROM shipment WHERE qty BETWEEN 300 AND 750;

--7
SELECT DISTINCT p.pname FROM part p INNER JOIN shipment s ON p.pno = s.pno WHERE s.qty BETWEEN 200 AND 750;

--8
SELECT DISTINCT s.sname FROM supplier s INNER JOIN shipment sh ON s.sno = sh.sno WHERE sh.pno IN (2, 4);

--9
SELECT COUNT(*), s.sno FROM part p INNER JOIN shipment s ON s.pno = p.pno GROUP BY s.sno;

--10
SELECT * FROM supplier s WHERE 'Red' IN (SELECT DISTINCT p.color FROM shipment sh INNER JOIN part p ON p.pno = sh.pno WHERE sh.sno = s.sno);

--11
SELECT pno, pname FROM part WHERE pno IN (SELECT pno FROM shipment GROUP BY pno HAVING COUNT(*) > 2);

--12
SELECT * FROM supplier s WHERE NOT 'Red' IN (SELECT DISTINCT p.color FROM shipment sh INNER JOIN part p ON p.pno = sh.pno WHERE sh.sno = s.sno);

--13
-- SELECT * FROM supplier s WHERE 'Red' = ALL(SELECT DISTINCT p.color FROM shipment sh INNER JOIN part p ON p.pno = sh.pno WHERE sh.sno = s.sno);

--14
SELECT * FROM supplier WHERE sno NOT IN (SELECT DISTINCT sno FROM shipment);

--15
SELECT DISTINCT sno FROM shipment WHERE pno IN (SELECT pno FROM shipment WHERE sno = 2) AND sno <> 2;

--16
SELECT p.* FROM part p INNER JOIN shipment sh ON p.pno = sh.pno INNER JOIN supplier s ON s.sno = sh.sno WHERE s.sname = 'Blake';

--17
SELECT * FROM shipment WHERE NOT price IS NULL ORDER BY price DESC;

--18
SELECT * FROM supplier WHERE city IN (SELECT city FROM supplier WHERE sno = 1) AND sno <> 1;

--19
SELECT * FROM part WHERE pno IN (SELECT pno FROM shipment GROUP BY pno HAVING COUNT(*) > 1) ORDER BY pno;

--20
SELECT * FROM supplier WHERE status < (SELECT AVG(status) FROM supplier) ORDER BY sno;

--21
SELECT COUNT(*) FROM supplier;

--22
SELECT COUNT(*) FROM supplier WHERE sno IN (SELECT DISTINCT sno FROM shipment);

--23
SELECT s.sname, p.pname, price / qty FROM shipment sh INNER JOIN part p ON p.pno = sh.pno INNER JOIN supplier s ON s.sno = sh.sno WHERE (sh.price / sh.qty) = (SELECT MAX(price / qty) FROM shipment);

--24
SELECT s.* FROM (SELECT sno FROM shipment GROUP BY sno ORDER BY MAX(price) DESC) sa INNER JOIN supplier s ON sa.sno = s.sno WHERE ROWNUM < 3;

--25.
SELECT s.*, sa.total FROM (SELECT Sno, SUM(Price * Qty) AS total FROM Shipment GROUP BY Sno ORDER BY total DESC) sa INNER JOIN Supplier s ON sa.Sno = s.Sno WHERE ROWNUM < 2;

--26.
SELECT Sno, COUNT(Pno) FROM Shipment GROUP BY Sno;

--27.
SELECT Sname, Status FROM Supplier WHERE Sno = (SELECT Sno FROM Shipment GROUP BY Sno HAVING SUM(Qty) = 250);

--28.
SELECT Pname FROM Part WHERE Pno IN (SELECT Pno FROM Shipment GROUP BY Pno HAVING AVG(Qty) > );
SELECT Pno, AVG(Qty) FROM Shipment GROUP BY Pno;
SELECT Pno, SUM(Qty) FROM Shipment GROUP BY Pno;

--29.
DELETE FROM Part WHERE Pno = (SELECT * FROM(SELECT Pno FROM Shipment GROUP BY Pno ORDER BY SUM(Qty)) WHERE ROWNUM < 2);

--30.
UPDATE Supplier SET Status = 50 WHERE Sno = (SELECT * FROM (SELECT Sno FROM Shipment GROUP BY Sno ORDER BY SUM(Qty * Price)) WHERE ROWNUM < 2);

--31
CREATE VIEW Part_view AS SELECT p.pno, pname, color, weight, city, total_qty, total_cost  FROM part p INNER JOIN (SELECT pno, SUM(qty) as total_qty FROM shipment GROUP BY pno) pq ON pq.pno = p.pno INNER JOIN (SELECT pno, SUM(price * qty) as total_cost FROM shipment GROUP BY pno) ps ON ps.pno = p.pno;



