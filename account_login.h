/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#ifndef ACCOUNT_LOGIN_H
#define ACCOUNT_LOGIN_H

#include <string>
#include <fstream>
#include "account_user_list.h"
#include "account_login.h"

using namespace std;

class Login {
  private:
    Admin user_list;
    bool logged_on;
    int cur_user_index;

  public:
    //Default Constructor
    Login();


    //                         BIG THREE
/********************************************************************/
    ~Login(); //destructor

    Login (const Login &); //copy constructor

    Login& operator=(const Login & old_c); //assignment operator overload
/********************************************************************/




    bool site_welcome();
    string title_screen();




    
    char user_login();

    void display_user_login();
    bool login_username_attempt();
    bool login_password_attempt();
    string get_user_file();
};

#endif