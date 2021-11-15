/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 3
*/
// Header file for Website class
#ifndef WEBSITE_H
#define WEBSITE_H

#include <iostream>
using namespace std;
#include <cstring>

class Website
{
public:
    Website();
    Website(const Website &a_website);
    ~Website();

    bool set_topic(const char *webtopic);
    bool set_address(const char *webaddress);
    bool set_summary(const char *websummary);
    bool set_review(const char *webreview);
    bool set_rating(const unsigned int webrating);

    const char *get_topic() const;
    const char *get_address() const;
    const char *get_summary() const;
    const char *get_review() const;
    const unsigned int get_rating() const;

    const Website &operator=(const Website &a_website);
    friend ostream &operator<<(ostream &out, const Website &a_website);

private:
    char *topic, *address, *summary, *review;
    unsigned int rating;
};

#endif
