/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 1
*/
// Header file for Song class
#ifndef SONG_H
#define SONG_H

#include <iostream>
using namespace std;
#include <cstring>

class Song
{
public:
    Song();
    Song(const Song &aSong);
    ~Song();

    bool set_artist(const char *artist);
    bool set_title(const char *title);
    bool set_length(float length);
    bool set_likes(int likes);

    const char *get_artist() const;
    const char *get_title() const;
    float get_length();
    int get_likes();

    const Song &operator=(const Song &a_song);
    friend ostream &operator<<(ostream &out, const Song &a_song);

private:
    char *song_artist, *song_title;
    float song_length;
    int song_likes;
};

#endif
