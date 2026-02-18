INSERT INTO genre(name)
values  ('ROCK'),
        ('BLUES'),
        ('REGGAE')
;

INSERT INTO singer(name)
values  ('Metallica'),
        ('Rammstein'),
        ('Black Ace'),
        ('Leroy Carr'),
        ('Bob Marley'),
        ('Eek a mouse')
;

INSERT INTO genresinger(id_genre, id_singer)
values  (1, 1),
        (1, 2),
        (2, 3),
        (2, 4),
        (3, 5),
        (3, 6),
        (2, 6)
;


INSERT INTO album(name, year)
values  ('...And Justice for All', 1988),
        ('Herzeleid', 1995),
        ('Anywhere But Here', 2017),
        ('Hurry Down Sunshine', 1995),
        ('Stir it Up', 1981),
        ('Black Cowboy', 1996)
;

INSERT INTO singeralbum(id_album, id_singer)
values  (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6)
;

INSERT INTO track(album_id, name, duration)
values  (1, 'Harvester of Sorrow', 120),
        (1, 'one', 130),
        (2, 'Seemann', 240),
        (2, 'Laichzeit', 250),
        (3, 'Down', 330),
        (3, 'Short Changed', 340),
        (4, 'The song', 350),
        (4, 'Work song', 340),
        (5, 'Kaya', 230),
        (5, 'Crisis', 220),
        (6, 'Zum Galli', 110),
        (6, 'Good to me', 120),
        (6, 'New one', 90)
;

INSERT INTO collection(name, year)
values  ('Collection 1', 1995),
        ('Collection 2', 2000),
        ('Collection 3', 2010),
        ('Collection 4', 2020)
;

INSERT INTO trackcollection(id_track, id_collection)
values  (1, 1),
        (2, 1),
        (5, 1),
        (2, 2),
        (4, 2),
        (6, 2),
        (1, 3),
        (2, 3),
        (1, 4),
        (2, 4),
        (3, 4),
        (4, 4),
        (5, 4),
        (6, 4)
;
