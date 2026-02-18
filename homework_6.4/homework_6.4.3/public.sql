SELECT g.name, COUNT(gs.id_singer) AS singer_count
FROM genre g
JOIN genresinger gs ON g.id = gs.id_genre
GROUP BY g.name
ORDER BY singer_count DESC;

SELECT COUNT(track.id) FROM track
JOIN album ON track.id = album.id
WHERE album.year BETWEEN 2017 AND 2020; 

SELECT track.album_id, AVG(track.duration) FROM track
GROUP BY track.album_id
ORDER BY track.album_id;

SELECT s.id, s.name, a.year FROM singer s
JOIN singeralbum sa ON s.id = sa.id_singer
JOIN album a ON sa.id_album = a.id
GROUP BY s.id, s.name, a.year
HAVING a.year != 2017
ORDER BY a.year;

SELECT DISTINCT c.name FROM collection c
JOIN trackcollection tc ON c.id = tc.id_collection
JOIN track t ON tc.id_track = t.id
JOIN album a ON t.album_id = a.id
JOIN singeralbum sa ON a.id = sa.id_album
JOIN singer s ON sa.id_singer = s.id
WHERE s.name = 'Rammstein'