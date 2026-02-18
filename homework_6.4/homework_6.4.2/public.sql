SELECT name, duration FROM track
WHERE duration = (SELECT MAX(duration) FROM track);


SELECT name FROM track
WHERE duration >= 3.5*60;

SELECT name FROM collection
WHERE year BETWEEN 2018 AND 2020;

SELECT name FROM singer
WHERE name NOT LIKE '% %';

SELECT name FROM track
WHERE name LIKE '%My%';