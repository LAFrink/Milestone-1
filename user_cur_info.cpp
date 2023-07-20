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


using namespace std;


Stats::Stats(){}
Stats::Stats(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());

    fin >> this->f_name;
    fin >> this->l_name;
    fin >> this->height;
    fin >> this->weight;
    fin >> this->bf_percent;
    cout << this->f_name << " " << this->l_name << endl;
    cout << this->height << endl << this->weight << endl << this->bf_percent << endl;
	fin.close();
}
/********************************************************************/











// SETTERS
    void Stats::set_user_info(const string first, const string last, const float ht, const float wt, const float bf)
    {
        this->f_name = first;
        this->l_name = last;
        this->height = ht;
        this->weight = wt;
        this->bf_percent = bf;
    }
    void Stats::replace_user_info(Stats * st)
    {
        this->f_name = st->f_name;
        this->l_name = st->l_name;
        this->height = st->height;
        this->weight = st->weight;
        this->bf_percent = st->bf_percent;
    }
    void Stats::set_f_name(const string first)
    {
        this->f_name = first;
    }
    void Stats::set_l_name(const string last)
    {
        this->l_name = last;
    }
    void Stats::set_height(const float ht)
    {
        this->height = ht;
    }
    void Stats::set_weight(const float wt)
    {
        this->weight = wt;
    }
    void Stats::set_bf_percent(const float bf)
    {
        this->bf_percent = bf;
    }

    //GETTERS
    Stats& Stats::get_user_info()
    {
        return *this;
    }
    string Stats::get_f_name() const
    {
        return this->f_name;
    }
    string Stats::get_l_name() const
    {
        return this->l_name;
    }
    float Stats::get_height() const
    {
        return this->height;
    }
    float Stats::get_weight() const
    {
        return this->weight;
    }
    float Stats::get_bf_percent() const
    {
        return this->bf_percent;
    }









