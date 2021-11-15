/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 3
This module contains the code for the member functions of the class Website
*/
#include "website.h"



Website::Website() : topic(nullptr), address(nullptr), summary(nullptr), review(nullptr), rating(0)
{
}



Website::Website(const Website &a_website) : topic(nullptr), address(nullptr), summary(nullptr), review(nullptr), rating(0)
{
    // copy constructer
    *this = a_website;
}



Website::~Website()
{
    // Destructor member function
    if (this->topic)
    {
        delete[] this->topic;
    }
    if (this->address)
    {
        delete[] this->address;
    }
    if (this->summary)
    {
        delete[] this->summary;
    }
    if (this->review)
    {
        delete[] this->review;
    }
    this->topic = nullptr;
    this->address = nullptr;
    this->summary = nullptr;
    this->review = nullptr;
}



bool Website::set_topic(const char *webtopic)
{
    /*
    This member function sets the topic for a Website object
    INPUT:
        grpname: The pointer to the char array that contains the name of the topic
                 that need to be set as website topic
    OUTPUT:
        true if successful.
    */
    if (this->topic)
    {
        delete[] this->topic;
    }
    this->topic = new char[strlen(webtopic) + 1];
    strcpy(this->topic, webtopic);
    return true;
}



bool Website::set_address(const char *webaddress)
{
    /*
    This member function sets the address of the website
    INPUT:
        spreq: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->address)
    {
        delete[] this->address;
    }
    this->address = new char[strlen(webaddress) + 1];
    strcpy(this->address, webaddress);
    return true;
}



bool Website::set_summary(const char *websummary)
{
    /*
    This member function sets the summary of the website
    INPUT:
        name: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->summary)
    {
        delete[] this->summary;
    }
    this->summary = new char[strlen(websummary) + 1];
    strcpy(this->summary, websummary);
    return true;
}



bool Website::set_review(const char *webreview)
{
    /*
    This member function sets the review of the website
    INPUT:
        contact: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->review)
    {
        delete[] this->review;
    }
    this->review = new char[strlen(webreview) + 1];
    strcpy(this->review, webreview);
    return true;
}



bool Website::set_rating(const unsigned int webrating)
{
    /*
    This member function sets the rating of the website
    INPUT:
        promo: Flag inputted by the user
    OUTPUT:
        true if successful.
    */
    this->rating = webrating;
    return true;
}



const Website &Website::operator=(const Website &a_website)
{
    /*
    Overloaded operator =
    OUTPUT:
        Song object
    */
    if (this == &a_website)
    {
        return *this;
    }
    set_topic(a_website.topic);
    set_address(a_website.address);
    set_summary(a_website.summary);
    set_review(a_website.review);
    set_rating(a_website.rating);
    return *this;
}



ostream &operator<<(ostream &out, const Website &a_website)
{
    /*
    Overloaded operator <<
    This friend function contain instructions for outputting the Song object
    */
    out << "  Topic:  " << a_website.topic << endl;
    out << "Address:  " << a_website.address << endl;
    out << "Summary:  " << a_website.summary << endl;
    out << " Review:  " << a_website.review << endl;
    out << " Rating:  " << a_website.rating << endl;
    return out;
}



const char *Website::get_topic() const
{
    // returns encapsulated attribute
    return this->topic;
}



const char *Website::get_address() const
{
    // returns encapsulated attribute
    return this->address;
}



const char *Website::get_summary() const
{
    // returns encapsulated attribute
    return this->summary;
}



const char *Website::get_review() const
{
    // returns encapsulated attribute
    return this->review;
}



const unsigned int Website::get_rating() const
{
    // returns encapsulated attribute
    return this->rating;
}
