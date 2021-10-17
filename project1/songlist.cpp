/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 1
This module contains the code for the member functions of the class Song
*/

#include "songlist.h"

//implementations for the member functions of SongList class

// *****************************************************************************
//                          PUBLIC MEMBER FUNCTIONS
//   (Private member functions are listed after the public member functions)
// *****************************************************************************

SongList::SongList() : head(nullptr), tail(nullptr), size(0) {}



SongList::~SongList()
{
    // destructor
    destroy();
}



void SongList::destroy()
{
    /*
    Member function to destroy the linked list
    INPUT:
        None
    OUTPUT:
        None
    */
    Node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}



bool SongList::add(const Song aSong)
{
    /*
    Member function to add a data to the linked list
    INPUT:
        aSong: A song object that needs to be added to the end of the linked list
    OUTPUT:
        true if successful
    */
    Node *newnode = new Node(aSong);
    if (!head)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    size++;
    return true;
}



void SongList::display_song_list_with_menu()
{
    /*
    Member function to display the song list in menu format prefixed with an index
    Notes:
        Displays a helpful message if there are no songs in the song list.
    INPUT:
        None
    OUTPUT:
        NONE
    */
    Node *curr = head;
    int counter = 1;
    cout << endl;
    cout << endl;
    while (curr)
    {
        cout << "[" << counter << "] " << *(curr->data) << endl;
        curr = curr->next;
        counter++;
    }
    cout << endl;
    if (size == 0)
        cout << "No songs in the list.  List is empty!" << endl;
    cout << "Total number of songs: " << size << endl;
    cout << endl;
    cout << endl;
}



const int SongList::get_list_size()
{
    // Returns the current size of the list
    return size;
}



bool SongList::set_new_likes(const int song_counter, const int likes)
{
    /*
    Takes in the song index and the new number of likes from the user and then
    updates the number of likes for the song with that index
    INPUT:
        song_counter: The index of the song in the likes of which need to be altered
        likes: The new number of likes that need to be set
    OUTPUT:
        true if successful
    */
    bool update_flag = set_new_likes_helper(song_counter, likes, 0, head);
    return update_flag;
}



bool SongList::remove_songs_fewer_than_likes(const int cutoff_likes)
{
    /*
    Takes in a cutoff number of likes inputted by the user and then deletes
    all songs from the list with likes fewer than the cutoff number of likes
    INPUT:
        cutoff_likes: The number of likes that is used as a decision making metric
                      to keep or delete a song
    OUTPUT:
        true if successful
    */
    Node *curr = head;
    int counter = 1;
    Node *intermed;

    cout << endl;
    while (curr)
    {
        if (curr->data->get_likes() < cutoff_likes)
        {
            cout << "Deleting... [" << counter << "] " << *(curr->data) << endl;
            intermed = curr;
            delete_a_song(curr);
            curr = curr->next;
            delete intermed;
        }
        else
        {
            curr = curr->next;
        }
        counter++;
    }
    cout << endl;
    cout << endl;
    return true;
}



const SongList SongList::get_songs_by_artist(const char *artist_name)
{
    /*
    Finds songs by a given artist name
    INPUT:
        artist_name: name of the artist that need to be searched in the linked list
    OUTPUT:
        A new linked list that only contain a song by artist given by artist_name
    */
    SongList newSongList;
    Node *curr = head;

    while (curr)
    {
        if (strcmp(curr->data->get_artist(), artist_name) == 0)
        {
            newSongList.add(*(curr->data));
        }
        curr = curr->next;
    }

    return newSongList.sort_by_likes();
}



const SongList &SongList::operator=(const SongList &aSongList)
{
    /*
    Overloaded operator =
    */
    if (this == &aSongList)
        return *this;
    destroy();
    size = aSongList.size;

    if (!aSongList.head)
    {
        head = tail = nullptr;
        return *this;
    }

    Node *newNode = new Node(*(aSongList.head->data));
    head = tail = newNode;

    Node *nextSrc = aSongList.head->next;
    Node *nextDes = head;
    while (nextSrc)
    {
        newNode = new Node(*(nextSrc->data));
        nextDes->next = newNode;
        newNode->prev = nextDes;
        nextSrc = nextSrc->next;
        nextDes = nextDes->next;
    }
    tail = nextDes;
    return *this;
}



ostream &operator<<(ostream &out, const SongList &aSongList)
{
    /*
    Overloaded operator to output the list
    */
    SongList::Node *curr;

    out << endl
        << "Displaying the list ... " << endl;
    for (curr = aSongList.head; curr; curr = curr->next)
    {
        out << *(curr->data) << endl;
    }
    out << endl;
    out << "Total number of songs in the list: " << aSongList.size << endl;

    return out;
}



void SongList::loadFromFile(const char *fileName)
{
    /*
    Member function to load test cases song list from a file
    INPUT:
        filename: name of the file that contains the test data set
    OUTPUT:
        None
    */
    ifstream fh;
    Song currSong;
    const int MAX_CHAR = 256;
    char currArtist[MAX_CHAR];
    char currTitle[MAX_CHAR];
    char temp[MAX_CHAR];
    float currLen;
    int currLikes;

    fh.open(fileName);
    if (!fh)
    {
        std::cout << "Fail to open " << fileName << " for reading." << std::endl;
        exit(1);
    }

    fh.getline(currArtist, MAX_CHAR, ',');
    while (!fh.eof())
    {
        fh.getline(currTitle, MAX_CHAR, ',');
        fh.getline(temp, MAX_CHAR, ',');
        currLen = atof(temp);
        fh.getline(temp, MAX_CHAR, '\n');
        currLikes = atoi(temp);

        currSong.set_artist(currArtist);
        currSong.set_title(currTitle);
        currSong.set_length(currLen);
        currSong.set_likes(currLikes);
        add(currSong);

        fh.getline(currArtist, MAX_CHAR, ',');
    }
}



void SongList::saveToFile(const char *fileName) const
{
    /*
    Member function to save a song list out to a file
    INPUT:
        filename: name of the file that contains the test data set
    OUTPUT:
        None
    */
    ofstream out;

    out.open(fileName);
    if (!out)
    {
        cerr << "Fail to open " << fileName << " for writing!" << endl;
        exit(1);
    }

    for (Node *curr = head; curr; curr = curr->next)
    {
        out << curr->data->get_artist() << ',' << curr->data->get_title() << ',' << curr->data->get_length() << ',' << curr->data->get_likes() << endl;
    }
    out.close();
}



// *****************************************************************************
//                PRIVATE MEMBER FUNCTIONS LISTED BELOW
// *****************************************************************************


bool SongList::delete_a_song(const Node *curr)
{
    /*
    Helper function to delete a song from the linked list.  The pointer to the 
    node getting deleted is passed as an input to this function.
    INPUT:
        curr: ponter to the node of the linked list that need to be deleted.
    OUTPUT:
        true if successful
    */
    bool deleted = false;

    if (curr->prev)
    {
        curr->prev->next = curr->next;
    }
    else
    {
        head = curr->next;
        if (curr->next)
        {
            curr->next->prev = nullptr;
        }
    }
    if (curr->next)
    {
        curr->next->prev = curr->prev;
    }
    else
    {
        tail = curr->prev;
        if (curr->prev)
        {
            curr->prev->next = nullptr;
        }
    }
    // delete curr;
    deleted = true;
    --size;
    return deleted;
}



void SongList::add_song_at_head(const Song aSong)
{
    /*
    Member function to add a song at head.  This is a helper function for the
    function to sort songs by order of popularity
    INPUT:
        aSong: A song object that need to be inserted at the head of the linked list
    OUTPUT:
        None
    */
    Node *newnode = new Node(aSong);
    if (!head)
    {
        add(aSong);
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        size++;
    }
}



void SongList::add_song_at_curr(const Song aSong, Node *curr)
{
    /*
    Member function to add a song between current node and next node.  This is a
    helper function for the function to sort songs by order of popularity
    INPUT:
        aSong: A song object that need to be inserted into the linked list
        curr: A pointer to the node after which the song object need to be inserted
    OUTPUT:
        None
    */
    Node *newnode = new Node(aSong);
    if (!curr->next)
    {
        add(aSong);
    }
    else
    {
        newnode->next = curr->next;
        newnode->prev = curr;

        curr->next->prev = newnode;
        curr->next = newnode;
    }
}



const SongList SongList::sort_by_likes()
{
    /*
    Helper function that generates a new linked list that is sorted by number of likes
    INPUT:
        None
    OUTPUT:
        a new linked list that is sorted by order of popularity
    */
    SongList newSongList;
    Node *curr = head;
    Node *newCurr;
    int curr_likes, next_likes, likes;
    bool flag;

    while (curr)
    {
        if ((!newSongList.head) && (!newSongList.tail))
        {
            newSongList.add(*(curr->data));
        }
        else
        {
            flag = true;
            likes = curr->data->get_likes();
            newCurr = newSongList.head;
            while ((newCurr) && flag)
            {
                curr_likes = newCurr->data->get_likes();
                if ((!newCurr->prev) && (likes >= curr_likes))
                {
                    newSongList.add_song_at_head(*(curr->data));
                    flag = false;
                }
                else if ((!newCurr->next) && likes <= curr_likes)
                {
                    newSongList.add(*(curr->data));
                    flag = false;
                }
                else
                {
                    next_likes = newCurr->next->data->get_likes();
                    if ((likes >= next_likes) && (likes <= curr_likes))
                    {
                        newSongList.add_song_at_curr(*(curr->data), newCurr);
                        flag = false;
                    }
                }
                newCurr = newCurr->next;
            }
        }
        curr = curr->next;
    }
    return newSongList;
}



bool SongList::set_new_likes_helper(const unsigned int index, const int likes, unsigned int counter, const Node *curr)
{
    /*
    Helper function for setting new likes that works recursively.
    INPUT:
        index: The index of the song in the linked list that need to changed
        likes: The new number of likes that need to be set
        counter: a counter variable to keep track of how far away from head we currently are
        curr: pointer to the current node
    OUTPUT:
        true if successful
    */
    bool update_flag = false;

    counter++;
    if (counter == index)
    {
        cout << "Updating # of likes for song ";
        cout << "[" << counter << "] " << *(curr->data) << " to " << likes << endl;
        curr->data->set_likes(likes);
        update_flag = true;
        cout << endl;
    }
    else
    {
        update_flag = set_new_likes_helper(index, likes, counter, curr->next);
    }
    return update_flag;
}
