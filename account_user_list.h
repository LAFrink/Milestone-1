/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H 

#include <string>
#include <fstream>
#include <iostream>
#include "account_info.h"

using namespace std;

class Admin {
  private:
    int num_accounts;
    Account* account_arr;
  public:
    Admin(); //default constructor

    //                         BIG THREE
/********************************************************************/
    ~Admin(); //destructor

    Admin (const Admin &); //copy constructor

    Admin& operator=(const Admin & old_u); //assignment operator overload
/********************************************************************/

    void load_account_arr();



    void print_accounts();


    Admin (int size);


   



    Account& search_by_username(string username);
    

    void add_to_accounts(Account& coffee_to_add);

    void remove_from_accounts(int index_of_account_on_site);


    void print_user_accounts();



    //GETTERS
    int get_num_accounts();
    string get_username(int i);
    string get_password(int i);


};

#endif