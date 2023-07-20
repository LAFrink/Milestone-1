/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#ifndef USER_MENU_H
#define USER_MENU_H

#include <string>
#include <fstream>
#include <iostream>
#include "user_cur_info.h"


using namespace std;

class History {
  private:
    int hist_len;             // integer to read each historical weigh in
    Stats* stat_hist_arr;     // array the=at holds each weigh in
    Stats cur_stat;
    Stats goal;                // goal stats

  public:
    //Default Constructor
    History();
    History(string filename);


    //                         BIG THREE
/********************************************************************/
    ~History(); //destructor

    History (const History &); //copy constructor

    History& operator=(const History & old_h); //assignment operator overload
/********************************************************************/


    void user_welcome();


    char user_menu();
    void display_user_menu();
    int user_menu_choice();

    void display_food_goals();
    void add_weigh_in();
    void update_goals();
    void help_menu();

    // LOAD DATA
    void load_data(); 


    // VIEW FUNCTIONS
    void view_history(); 
};

#endif