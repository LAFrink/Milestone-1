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
#include "user_cur_info.h"
#include "user_menu.h"


using namespace std;

History::History(){}

History::History(string filename)
{
    Stats temp = Stats(filename);
    this->cur_stat.set_f_name(temp.get_f_name());
    this->cur_stat.set_l_name(temp.get_l_name());
    this->cur_stat.set_height(temp.get_height());
    this->cur_stat.set_weight(temp.get_weight());
    this->cur_stat.set_bf_percent(temp.get_bf_percent());
}


    //                         BIG THREE
/********************************************************************/
History::~History() //destructor
{
}
History::History (const History & old_h) //copy constructor
{
}


History& History::operator=(const History & old_h) //assignment operator overload
{
    cout << "AOO called" << endl;
	this->hist_len = old_h.hist_len;

	//free memory first
	if (this->stat_hist_arr != NULL){
		delete [] this->stat_hist_arr;
		this->stat_hist_arr = NULL;
	}
	//deep copy
	this->stat_hist_arr = new Stats [this->hist_len];
	for (int i = 0; i < this->hist_len; ++i)
	{
		this->stat_hist_arr[i] = old_h.stat_hist_arr[i];
	}
	return *this;
}

void History::user_welcome()
{
    char menu_choice;
    cout << "Welcome, " << this->cur_stat.get_f_name() << "!" << endl;
    cout << endl << "Your current Stats:" << endl;
    cout << "Height: " << this->cur_stat.get_height() << " inches" << endl;
    cout << "Weight: " << this->cur_stat.get_weight() << " pounds" << endl;
    cout << "bodyfat: " << this->cur_stat.get_bf_percent() << " %" << endl << endl;

    menu_choice = user_menu();

    if (menu_choice == 'F')
    {
        return;
    }
    
}


// Functions that control the options a customer can see and use




char History::user_menu()
{
    int choice;
    while (true)
    {
        choice = user_menu_choice();
        if (choice == 5)
        {
            return 'F';
        }
        else if (choice == 4)
        {
            help_menu();
        }
        else if (choice == 3)
        {
            update_goals();
        }
        else if (choice == 2)
        {
            add_weigh_in();
        }
        else if (choice == 1)
        {
            display_food_goals();
        }
        cout << endl;
    }
}


void History::display_user_menu()
{

    cout << "Menu Options: " << endl;
    cout << "   1. View daily food goals" << endl;
    cout << "   2. Add weigh in" << endl;
    cout << "   3. Update Goals" << endl;
    cout << "   4. Helpful Information" << endl;
    cout << "   5. Log out" << endl;
    cout << endl << "Selection: ";
}


int History::user_menu_choice()
{
    int choice;
    display_user_menu();

    while (!(cin >> choice))
    {
        cout << endl << "Invalid Input: Enter an integer between 1 and 5" << endl;
        display_user_menu();
        cin.clear();
        cin.ignore(123, '\n');
    }
    while (choice > 5 or choice < 1)
    {
        cout << endl << "Invalid Input: Enter an integer between 1 and 5" << endl;
        cout << endl;
        choice = user_menu_choice();
        cin.clear();
    }
    cin.clear();
    return choice;
}



void History::display_food_goals()
{
    cout << endl << "To Be Added" << endl;
}
void History::add_weigh_in()
{
    cout << endl << "To Be Added" << endl;
}
void History::update_goals()
{
    cout << endl << "To Be Added" << endl;
}
void History::help_menu()
{
    cout << endl << "To Be Added" << endl;
}




// LOAD DATA
void History::load_data(){} 


// VIEW FUNCTIONS
void History::view_history(){}


