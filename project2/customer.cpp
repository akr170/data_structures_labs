/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
This module contains the code for the member functions of the class Customer
*/
#include "customer.h"



Customer::Customer() : group_name(nullptr), special_requests(nullptr), contact_name(nullptr), contact_email(nullptr), promo_material(false), group_size(0)
{
}



Customer::Customer(const Customer &a_customer) : group_name(nullptr), special_requests(nullptr), contact_name(nullptr), contact_email(nullptr), promo_material(false), group_size(0)
{
    //copy constructer
    *this = a_customer;
}



Customer::~Customer()
{
    // Destructor member function
    if (this->group_name)
    {
        delete[] this->group_name;
    }
    if (this->special_requests)
    {
        delete[] this->special_requests;
    }
    if (this->contact_name)
    {
        delete[] this->contact_name;
    }
    if (this->contact_email)
    {
        delete[] this->contact_email;
    }
    this->group_name = nullptr;
    this->special_requests = nullptr;
    this->contact_name = nullptr;
    this->contact_email = nullptr;
}



bool Customer::set_group_name(const char *grpname)
{
    /*
    This member function sets the group name for a Customer object
    INPUT:
        grpname: The pointer to the char array that contains the name of the artist
                 that need to be set as Song artist
    OUTPUT:
        true if successful.
    */
    if (this->group_name)
    {
        delete[] this->group_name;
    }
    this->group_name = new char[strlen(grpname) + 1];
    strcpy(this->group_name, grpname);
    return true;
}



bool Customer::set_special_rq(const char *spreq)
{
    /*
    This member function sets the special request information for a customer group
    INPUT:
        spreq: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->special_requests)
    {
        delete[] this->special_requests;
    }
    this->special_requests = new char[strlen(spreq) + 1];
    strcpy(this->special_requests, spreq);
    return true;
}



bool Customer::set_contact_name(const char *name)
{
    /*
    This member function sets the customer contact name for a customer group
    INPUT:
        name: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->contact_name)
    {
        delete[] this->contact_name;
    }
    this->contact_name = new char[strlen(name) + 1];
    strcpy(this->contact_name, name);
    return true;
}



bool Customer::set_contact_email(const char *contact)
{
    /*
    This member function sets the customer contact email for a customer group
    INPUT:
        contact: The pointer to the char array that contains the user input
    OUTPUT:
        true if successful.
    */
    if (this->contact_email)
    {
        delete[] this->contact_email;
    }
    this->contact_email = new char[strlen(contact) + 1];
    strcpy(this->contact_email, contact);
    return true;
}



bool Customer::set_promo_mat(const bool promo)
{
    /*
    This member function sets the flag that indicates to the program whether the
    customer want to receive promotional material or not.
    INPUT:
        promo: Flag inputted by the user
    OUTPUT:
        true if successful.
    */
    this->promo_material = promo;
    return true;
}



bool Customer::set_group_size(const unsigned int grpsize)
{
    /*
    This member function sets the group size.
    INPUT:
        promo: Value inputted by the user
    OUTPUT:
        true if successful.
    */
    this->group_size = grpsize;
    return true;
}



const Customer &Customer::operator=(const Customer &a_customer)
{
    /*
    Overloaded operator =
    OUTPUT:
        Song object
    */
    if (this == &a_customer)
    {
        return *this;
    }
    set_group_name(a_customer.group_name);
    set_group_size(a_customer.group_size);
    set_special_rq(a_customer.special_requests);
    set_promo_mat(a_customer.promo_material);
    set_contact_name(a_customer.contact_name);
    set_contact_email(a_customer.contact_email);
    return *this;
}



ostream &operator<<(ostream &out, const Customer &a_customer)
{
    /*
    Overloaded operator <<
    This friend function contain instructions for outputting the Song object
    */
    out << a_customer.group_name << " - Party of: " << a_customer.group_size;
    return out;
}



const char *Customer::get_group_name() const
{
    // returns encapsulated attribute
    return this->group_name;
}



const unsigned int Customer::get_group_size()
{
    // returns encapsulated attribute
    return this->group_size;
}



const char *Customer::get_special_rq() const
{
    // returns encapsulated attribute
    return this->special_requests;
}



const bool Customer::get_promo_mat()
{
    // returns encapsulated attribute
    return this->promo_material;
}



const char *Customer::get_contact_name() const
{
    // returns encapsulated attribute
    return this->contact_name;
}



const char *Customer::get_contact_email() const
{
    // returns encapsulated attribute
    return this->contact_email;
}
