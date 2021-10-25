/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
This module contains the code for the member functions of the class CustomerInfo
*/
#include "customerinfo.h"



CustomerInfo::CustomerInfo() : contact_name(nullptr), contact_email(nullptr)
{
}



CustomerInfo::CustomerInfo(const CustomerInfo &a_customer) : contact_name(nullptr), contact_email(nullptr)
{
    //copy constructer
    *this = a_customer;
}



CustomerInfo::~CustomerInfo()
{
    // Destructor member function
    if (this->contact_name)
    {
        delete[] this->contact_name;
    }
    if (this->contact_email)
    {
        delete[] this->contact_email;
    }
    this->contact_name = nullptr;
    this->contact_email = nullptr;
}



bool CustomerInfo::set_contact_name(const char *name)
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



bool CustomerInfo::set_contact_email(const char *contact)
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



const CustomerInfo &CustomerInfo::operator=(const CustomerInfo &a_customer)
{
    /*
    Overloaded operator =
    */
    if (this == &a_customer)
    {
        return *this;
    }
    set_contact_name(a_customer.contact_name);
    set_contact_email(a_customer.contact_email);
    return *this;
}



ostream &operator<<(ostream &out, const CustomerInfo &a_customer)
{
    /*
    Overloaded operator <<
    This friend function contain instructions for outputting the Song object
    */
    out << a_customer.contact_name << " - " << a_customer.contact_email;
    return out;
}



const char *CustomerInfo::get_contact_name() const
{
    // returns encapsulated attribute
    return this->contact_name;
}



const char *CustomerInfo::get_contact_email() const
{
    // returns encapsulated attribute
    return this->contact_email;
}
