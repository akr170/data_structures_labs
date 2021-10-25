/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
*/
// Header file for Customer class
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
#include <cstring>

class Customer
{
public:
    Customer();
    Customer(const Customer &a_customer);
    ~Customer();

    bool set_group_name(const char *grpname);
    bool set_group_size(const unsigned int grpsize);
    bool set_special_rq(const char *spreq);
    bool set_promo_mat(const bool promo);
    bool set_contact_name(const char *name);
    bool set_contact_email(const char *contact);

    const char *get_group_name() const;
    const unsigned int get_group_size();
    const char *get_special_rq() const;
    const bool get_promo_mat();
    const char *get_contact_name() const;
    const char *get_contact_email() const;

    const Customer &operator=(const Customer &a_customer);
    friend ostream &operator<<(ostream &out, const Customer &a_customer);

private:
    char *group_name, *special_requests;
    char *contact_name, *contact_email;
    bool promo_material;
    unsigned int group_size;
};

#endif
