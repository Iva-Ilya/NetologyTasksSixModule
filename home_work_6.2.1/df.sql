CREATE TABLE IF NOT EXISTS List_of_genres (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS Genre (
	id INTEGER PRIMARY KEY REFERENCES List_of_genres(id),
	name VARCHAR(40) NOT NULL
);


CREATE TABLE Artist(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50)
);

CREATE TABLE GenreArtist(  
    id_Genre INTEGER NOT NULL REFERENCES Genre(id),
    id_Artist INTEGER NOT NULL REFERENCES Artist(id),
    CONSTRAINT PK PRIMARY KEY (id_Genre, id_Artist)
);

CREATE TABLE Album(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50),
    year INTEGER
);

CREATE TABLE ArtistAlbum(  
    id_Album INTEGER NOT NULL REFERENCES Album(id),
    id_Artist INTEGER NOT NULL REFERENCES Artist(id),
    CONSTRAINT PK2 PRIMARY KEY (id_Album, id_Artist)
);

CREATE TABLE Track(  
    id SERIAL PRIMARY KEY,
    album_id INTEGER REFERENCES Album(id),
    name VARCHAR(50),
    duration INTEGER
);

CREATE TABLE Collection(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50),
    year INTEGER
);


CREATE TABLE CollectionTrack(  
    id_Track INTEGER NOT NULL REFERENCES Track(id),
    id_Collection INTEGER NOT NULL REFERENCES Collection(id),
    PRIMARY KEY (id_Track, id_Collection)
);