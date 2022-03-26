TRUNCATE TABLE Titanic;

CREATE TABLE Titanic (id INT, last VARCHAR(255), first VARCHAR(255), gender CHAR(1), age INT, travel_class INT, fare FLOAT, embarked VARCHAR(255), survived VARCHAR(255));

ALTER TABLE Titanic DROP COLUMN id;

ALTER TABLE Titanic ADD passenger_type VARCHAR(255);

ALTER TABLE Titanic MODIFY first VARCHAR(255) PRIMARY KEY;

ALTER TABLE Titanic ADD CONSTRAINT fare_check CHECK(fare < 300);

ALTER TABLE Titanic ADD CONSTRAINT gender_check CHECK(gender IN ('F', 'M'));

ALTER TABLE Titanic MODIFY last VARCHAR(255) NOT NULL;
ALTER TABLE Titanic MODIFY embarked VARCHAR(255) NOT NULL;
ALTER TABLE Titanic MODIFY survived VARCHAR(255) NOT NULL;

--ALTER TABLE Titanic DROP CONSTRAINT survived_check;

ALTER TABLE Titanic ADD CONSTRAINT survived_check CHECK(survived IN ('yes', 'no'));

ALTER TABLE Titanic ADD CONSTRAINT class_check CHECK(travel_class IN (1, 2, 3));

UPDATE Titanic SET embarked='Cherbourg-Octeville' WHERE embarked = 'Cherbourg';

UPDATE Titanic SET passenger_type=CASE WHEN fare = 0 THEN 'CREW' ELSE 'PASSENGER' END;

SELECT first, age, embarked FROM Titanic;

SELECT first, last, age FROM Titanic WHERE passenger_type = 'PASSENGER' AND last LIKE 'A%';

SELECT * FROM Titanic WHERE embarked = 'Queenstown';

SELECT * FROM Titanic WHERE age BETWEEN 50 AND 70;

SELECT * FROM titanic WHERE LENGTH(last) <= 7;

SELECT COUNT(*) FROM titanic WHERE travel_class = 1;

SELECT COUNT(*) FROM titanic WHERE survived = 'yes';

SELECT gender, COUNT(*) FROM titanic WHERE survived = 'yes' GROUP BY gender;

SELECT travel_class, gender, COUNT(*) FROM titanic WHERE survived = 'yes' GROUP BY gender, travel_class ORDER BY COUNT(*) DESC;

--SELECT MIN(fare) FROM titanic WHERE fare <> 0;
--SELECT MAX(fare) FROM titanic WHERE fare <> 0;

SELECT MAX(fare) - MIN(fare) FROM titanic WHERE fare <> 0;

SELECT gender, COUNT(*) FROM titanic WHERE embarked = 'Southampton' GROUP BY gender;

SELECT MAX(fare) FROM titanic WHERE embarked = 'Cherbourg';
SELECT MIN(fare) FROM titanic WHERE embarked = 'Cherbourg';
SELECT AVG(fare) FROM titanic WHERE embarked = 'Cherbourg';

SELECT last FROM titanic WHERE age IS NULL ORDER BY last;

SELECT travel_class, MAX(fare) FROM titanic GROUP BY travel_class;
SELECT travel_class, MIN(fare) FROM titanic WHERE fare <> 0 GROUP BY travel_class;
SELECT travel_class, AVG(fare) FROM titanic GROUP BY travel_class;

SELECT travel_class, COUNT(*) FROM titanic GROUP BY travel_class HAVING COUNT(*) > 10;

SELECT * FROM titanic WHERE gender = 'F' AND age = (SELECT MIN(age) FROM titanic WHERE gender = 'F');

SELECT * FROM titanic WHERE travel_class = 1 ORDER BY age ASC;

SELECT gender, ROUND(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM titanic), 2) as death_percentage FROM titanic WHERE survived = 'no' GROUP BY gender;

SELECT * FROM titanic WHERE age IN ((SELECT MIN(age) FROM titanic WHERE gender = 'F' AND embarked = 'Queenstown') , (SELECT MIN(age) FROM titanic WHERE gender = 'M' AND embarked = 'Queenstown')) AND embarked = 'Queenstown';

--SELECT travel_class, COUNT(*) as female_passengers FROM titanic WHERE gender = 'F' GROUP BY travel_class ORDER BY female_passengers;

SELECT * FROM titanic ti WHERE fare IN (SELECT MAX(fare) FROM titanic WHERE travel_class = ti.travel_class) ORDER BY travel_class;

SELECT MAX(embarked) FROM titanic WHERE gender = 'F';

SELECT travel_class, COUNT(*) FROM titanic GROUP BY travel_class HAVING COUNT(*) > 10;

SELECT * FROM titanic ti WHERE gender = 'M' and age > (SELECT MAX(age) FROM titanic WHERE gender = 'F' and travel_class = ti.travel_class) ORDER BY travel_class;

SELECT * FROM titanic ORDER BY embarked;

SELECT * FROM (SELECT gender, COUNT(*) as survivors FROM titanic WHERE survived = 'yes' GROUP BY gender ORDER BY survivors DESC) WHERE ROWNUM = 1;

DESC titanic;