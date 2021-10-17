/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 1
This module contains the code for the member functions of the class Song
*/
#include "song.h"



Song::Song() : song_artist(nullptr), song_title(nullptr), song_length(0), song_likes(0)
{
}



Song::Song(const Song &aSong) : song_artist(nullptr), song_title(nullptr), song_length(0), song_likes(0)
{
    *this = aSong;
}



Song::~Song()
{
    // Destructor member function
    if (this->song_artist)
    {
        delete[] this->song_artist;
    }
    if (this->song_title)
    {
        delete[] this->song_title;
    }
    this->song_artist = nullptr;
    this->song_title = nullptr;
}



bool Song::set_artist(const char *artist)
{
    /*
    This member function sets the artist name for a Song object
    INPUT:
        artist: The pointer to the char array that contains the name of the artist
                that need to be set as Song artist
    OUTPUT:
        true if successful.
    */
    if (this->song_artist)
    {
        delete[] this->song_artist;
    }
    this->song_artist = new char[strlen(artist) + 1];
    strcpy(this->song_artist, artist);
    return true;
}



bool Song::set_title(const char *title)
{
    /*
    This member function sets the title name for a Song object
    INPUT:
        title: The pointer to the char array that contains the name of the title
               that need to be set as Song title
    OUTPUT:
        true if successful.
    */
    if (this->song_title)
    {
        delete[] this->song_title;
    }
    this->song_title = new char[strlen(title) + 1];
    strcpy(this->song_title, title);
    return true;
}



bool Song::set_length(float length)
{
    /*
    This member function sets the length of the song in the Song object
    INPUT:
        length: The length that need to be set
    OUTPUT:
        true if successful
    */
    this->song_length = length;
    return true;
}



bool Song::set_likes(int likes)
{
    /*
    This member function sets the number of likes of the song in the Song object
    INPUT:
        likes: The number of likes that need to be set
    OUTPUT:
        true if successful
    */
    this->song_likes = likes;
    return true;
}



const Song &Song::operator=(const Song &a_song)
{
    /*
    Overloaded operator =
    SongA = SongB means:
        SongA.song_artist = SongB.song_artist
        SongA.song_title = SongB.song_title
        SongA.song_length = SongB.song_length
        SongA.song_likes = SongB.song_likes
    OUTPUT:
        Song object
    */
    if (this == &a_song)
    {
        return *this;
    }
    set_artist(a_song.song_artist);
    set_title(a_song.song_title);
    set_length(a_song.song_length);
    set_likes(a_song.song_likes);
    return *this;
}



ostream &operator<<(ostream &out, const Song &a_song)
{
    /*
    Overloaded operator <<
    This friend function contain instructions for outputting the Song object
    */
    out << a_song.song_artist << " - " << a_song.song_title << " - ";
    out << a_song.song_length << " - " << a_song.song_likes << " likes";
    return out;
}



const char *Song::get_artist() const
{
    // Gets the song artist name for the song object
    return this->song_artist;
}



const char *Song::get_title() const
{
    // Gets the song title name for the song object
    return this->song_title;
}



float Song::get_length()
{
    //Gets the song length name for the song object
    return this->song_length;
}



int Song::get_likes()
{
    //Gets the song likes for the song object
    return this->song_likes;
}
