/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/
#ifndef USER_CUR_INFO_H
#define USER_CUR_INFO_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Stats {
  private:
    string f_name; 
    string l_name; 
    float height; 
    float weight; 
    float bf_percent; 
  public:
    //Default Constructor
    Stats();

    
    Stats(string);
    






    // SETTERS
    void set_user_info(const string first, const string last, const float ht, const float wt, const float bf);
    void replace_user_info(Stats * st);
    void set_f_name(const string);
    void set_l_name(const string);
    void set_height(const float);
    void set_weight(const float);
    void set_bf_percent(const float);

    // GETTERS
    Stats& get_user_info();
    string get_f_name() const;
    string get_l_name() const;
    float get_height() const;
    float get_weight() const;
    float get_bf_percent() const;

};

#endif