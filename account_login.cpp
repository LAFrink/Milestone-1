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
#include "account_login.h"
#include "account_user_list.h"
#include "account_info.h"

using namespace std;


Login::Login(){
    this->user_list.load_account_arr();
}


//                         BIG THREE
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
Login::~Login()
{   //destructor
}
/*****************************************************************************/
Login::Login (const Login & old_c)
{  //copy constructor
    
}
/*****************************************************************************/
Login& Login::operator=(const Login & old_c)
{ //assignment operator overload
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/












//                                 LOGIN
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

bool Login::site_welcome(){
    char check;

    check = title_screen()[0];
    while (check != 'Q'){

        while (check == 'U')
        {
            check = user_login();

        }
        while (check == 'A')
        {
            //check = employee_menu();
            return false;
        }
        if (check == 'P')
        {
            return true;
        }
        
    }
    return false;
}
/*****************************************************************************/
string Login::title_screen(){
    string check;
    cout << endl << "Welcome to Deep Cut!" << endl;
    cout << "Are you a returning user (U), guest (To Be Added),or would you like to quit (Q)? ";
    cin >> check;
    while (check != "Q" && check != "U" && check != "A")
    {
        cout << endl << "Invalid input: please enter U, A, or Q." << endl;
        check = title_screen();
        cin.clear();
    }
    cin.clear();
    return check;
}


/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
















//                         CUSTOMER MENU
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
char Login::user_login(){
    int tries_remaining;
    bool namepass;
    bool passpass;

    namepass = login_username_attempt();
    if (namepass == false)
    {
        return 'Q';
    }
    passpass = login_password_attempt();
    if (passpass == false)
    {
        return 'Q';
    }
    else
    {
        return 'P';
    }
}




string Login::get_user_file()
{
    return this->user_list.get_username(this->cur_user_index) + ".txt";
}








/*****************************************************************************/
void Login::display_user_login()
{
}
/*****************************************************************************/
bool Login::login_username_attempt(){
    string username_attempt;
    bool success = false;

    cout << "Enter your username and password." << endl;
    cout << "Enter 1 to return to Main Menu" << endl;
    while (success == false)
    {
        cout << endl << "Username: ";
        cin >> username_attempt;
        if (username_attempt == "1")
        {
            return false;
        }
        for (int i = 0; i < this->user_list.get_num_accounts(); i++)
        {
            if (username_attempt == this->user_list.get_username(i))
            {
                this->cur_user_index = i;
                return true;
            }
        }
        if (success == false)
        {
            cout << endl << "Error: Username not found." << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    return false;
}


bool Login::login_password_attempt(){
    string pass_attempt;

    for (int i = 3; i > 0; i--)
    {
        cout << endl << "Password: ";
        cin >> pass_attempt;
        if (pass_attempt == this->user_list.get_password(this->cur_user_index))
        {
            return true;
        }
        else if (pass_attempt == "1")
        {
            return false;
        }
        cin.clear();
        
    }
    return false;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/












































