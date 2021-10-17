/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 1
*/
// Header file for the songlist class
#ifndef _SONG_LIST_
#define _SONG_LIST_

#include "song.h"
#include <fstream>

class SongList
{
public:
	SongList();
	~SongList();

	bool add(const Song aSong);
	void display_song_list_with_menu();
	const int get_list_size();
	bool set_new_likes(const int song_counter, const int likes);
	bool remove_songs_fewer_than_likes(const int cutoff_likes);
	const SongList get_songs_by_artist(const char *artist_name);

	const SongList &operator=(const SongList &aList);
	friend ostream &operator<<(ostream &out, const SongList &aSongList);

	void loadFromFile(const char *filename);
	void saveToFile(const char *fileName) const;

private:
	struct Node
	{
		Node(const Song &aSong)
		{
			data = new Song(aSong);
			prev = next = nullptr;
		}
		~Node()
		{
			delete data;
			data = nullptr;
			prev = next = nullptr;
		}
		Song *data;
		Node *prev, *next;
	};
	Node *head, *tail;
	int size;
	void destroy();
	bool delete_a_song(const Node *curr);
	void add_song_at_head(const Song aSong);
	void add_song_at_curr(const Song aSong, Node *curr);
	const SongList sort_by_likes();
	bool set_new_likes_helper(const unsigned int index, const int likes, unsigned int counter, const Node *curr);
};

#endif // _SONG_LIST_
