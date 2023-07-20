/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#include <string>
#include <fstream>
#include <iostream>
#include "account_info.h"

using namespace std;


//Default Constructor
Account::Account(){
    this->username = "new_user1234";
    this->password = "password1234";
}

   
// GETTERS
string Account::get_username() const{
    return this->username;
}
string Account::get_password() const{
    return this->password;
}




// SETTERS
void Account::set_account(const string username, const string password)
{
    this->username = username;
    this->password = password; 
}

void Account::change_username (const string username){
    this->username = username;
}



void Account::change_password (const string password){
    this->password = password; 
}




void Account::print_account_info() const{
    cout << "Username: " << this->username << endl;
    cout << "Password: " << this->password << endl;
}



void Account::load_account(ifstream& fin){
    fin >> this->username;
    fin >> this->password;
}
