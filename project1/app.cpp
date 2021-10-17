/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 1
*/

#include <iostream>
using namespace std;
#include "song.h"
#include "songlist.h"



void add_a_new_song(SongList &aSongList);
void edit_song_likes(SongList &aSongList);
void remove_songs(SongList &aSongList);
void find_songs_by_artist(SongList &aSongList);



int main()
{
	// Main function: Entry point for the code.
	SongList aSongList, newSongList;
	char filename[] = "songlist.txt";
	char choice_in; // variable to store user input (bad input is okay as we are storing it as char)
	int choice = 0; // variable to store user input after it is converted to int
	const char menu[] = "Menu Options:\n"
						"[1] Add a new song\n"
						"[2] Edit the number of likes for a song\n"
						"[3] Display all songs in the current list\n"
						"[4] Display all songs for an artist (in order of popularity)\n"
						"[5] Remove all songs with fewer than N likes\n"
						"[6] Exit the program\n";

	aSongList.loadFromFile(filename);

	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			add_a_new_song(aSongList);
			break;
		case 2:
			edit_song_likes(aSongList);
			break;
		case 3:
			aSongList.display_song_list_with_menu();
			break;
		case 4:
			find_songs_by_artist(aSongList);
			break;
		case 5:
			remove_songs(aSongList);
			break;
		}
		cout << menu << endl;
		cout << "Enter a choice from the above menu: ";
		cin >> choice_in;
		choice = (int)choice_in - 48;
	}
	return 0;
}



void add_a_new_song(SongList &aSongList)
{
	/*
	Gets the following input from the user
		song artist
		song title
		song length
		song likes
	and then creates a song object and adds it to the song list.
	INPUT:
		aSongList: The SongList object
	OUTPUT:
		None
	*/
	Song newSong;
	const int MAX_CHAR = 256;
	char newArtist[MAX_CHAR];
	char newTitle[MAX_CHAR];
	char temp[MAX_CHAR];
	float newLen;
	int newLikes;

	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "Enter new song information below" << endl;
	cout << "Enter artist name (expecting a string): ";
	cin.getline(newArtist, MAX_CHAR);
	cout << "Enter song title (expecting a string): ";
	cin.getline(newTitle, MAX_CHAR);
	cout << "Enter song length (expecting a float): ";
	cin.getline(temp, MAX_CHAR);
	newLen = atof(temp);
	cout << "Enter song likes (expecting an int): ";
	cin.getline(temp, MAX_CHAR);
	newLikes = atoi(temp);
	cout << endl;

	newSong.set_artist(newArtist);
	newSong.set_title(newTitle);
	newSong.set_length(newLen);
	newSong.set_likes(newLikes);
	aSongList.add(newSong);

	cout << "Added new song to the list." << endl;
	cout << endl;
}



void edit_song_likes(SongList &aSongList)
{
	/*
	Displays the song list to the user in a menu format and then asks the user
	to choose the song for which likes need to be edited
	And then asks the user to enter the number of likes for that particular song.
	INPUT:
		aSongList: The SongList object
	OUTPUT:
		None
	*/
	int song_counter = 0;
	int likes;

	aSongList.display_song_list_with_menu();
	if (aSongList.get_list_size() > 0)
	{
		cout << "Select the song for which the likes need to be changed (expecting int): ";
		cin >> song_counter;
		if ((song_counter < 1) || (song_counter > aSongList.get_list_size()))
		{
			cout << "Not a valid input.  Please try again." << endl;
		}
		else
		{
			cout << "Enter the new number of likes (expecting interger): ";
			cin >> likes;
			aSongList.set_new_likes(song_counter, likes);
		}
		cout << endl;
		cout << endl;
	}
}



void remove_songs(SongList &aSongList)
{
	/*
	Asks the user to enter the cutoff number of likes for deciding which songs need
	to be deleted.  All songs that have number of likes fewer than the cutoff number
	will be deleted.
	INPUT:
		aSongList: The SongList object
	OUTPUT:
		None
	*/
	int cutoff_likes;

	aSongList.display_song_list_with_menu();
	if (aSongList.get_list_size() > 0)
	{
		cout << "Enter the number of likes N for removing songs (expecting int): ";
		cin >> cutoff_likes;
		aSongList.remove_songs_fewer_than_likes(cutoff_likes);
	}
}



void find_songs_by_artist(SongList &aSongList)
{
	/*
	Asks the user to input the name of the artist for which the number of songs
	need to be displayed.
	The songs for the artist are displayed in order of popularity
	INPUT:
		aSongList: The SongList object
	OUTPUT:
		None
	*/
	const int MAX_CHAR = 256;
	char artist_name[MAX_CHAR];
	char temp[MAX_CHAR];
	SongList newSongList;

	if (aSongList.get_list_size() > 0)
	{
		cout << endl;
		cin.getline(temp, MAX_CHAR);
		cout << "Enter the artist name for which songs need to be displayed (expecting a string): ";
		cin.getline(artist_name, MAX_CHAR);
		newSongList = aSongList.get_songs_by_artist(artist_name);
		if (newSongList.get_list_size() == 0)
		{
			cout << endl;
			cout << "No songs were found in the list ";
			cout << "that belong to artist: " << artist_name << endl;
			cout << endl;
		}
		else
		{
			newSongList.display_song_list_with_menu();
		}
	}
	else
	{
		aSongList.display_song_list_with_menu();
	}
}
