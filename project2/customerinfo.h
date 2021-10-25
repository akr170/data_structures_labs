/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
*/
// Header file for CustomerInfo class
#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H

#include <iostream>
using namespace std;
#include <cstring>

class CustomerInfo
{
public:
    CustomerInfo();
    CustomerInfo(const CustomerInfo &a_customer);
    ~CustomerInfo();

    bool set_contact_name(const char *name);
    bool set_contact_email(const char *contact);

    const char *get_contact_name() const;
    const char *get_contact_email() const;

    const CustomerInfo &operator=(const CustomerInfo &a_customer);
    friend ostream &operator<<(ostream &out, const CustomerInfo &a_customer);

private:
    char *contact_name, *contact_email;
};

#endif
