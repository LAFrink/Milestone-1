/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Account { 
  private:
    string username;
    string password;
    
  public:

    //Default Constructor
    Account();

    //Getters
    string get_username() const;
    string get_password() const;

    //Setters
    void set_account(const string, const string);
    void change_username (const string);
    void change_password (const string);

    void load_account(ifstream& fin);
    
    //Print functions
    void print_account_info() const; 

};

#endif