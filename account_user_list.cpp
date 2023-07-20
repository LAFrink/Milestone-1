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
#include "account_user_list.h"

using namespace std;





Admin::Admin(){
}



Admin::Admin(int size) {
    this->num_accounts = size;
    this->account_arr = new Account [size];
}
//                         BIG THREE
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
Admin::~Admin(){   //destructor
    if (this->account_arr != NULL){
		delete [] this->account_arr;
		this->account_arr = NULL;
	}
}


Admin::Admin (const Admin & old_u){  //copy constructor
    cout << "CC called" << endl;
	this->num_accounts = old_u.num_accounts;

	//deep copy
	this->account_arr = new Account [this->num_accounts];
	for (int i = 0; i < this->num_accounts; ++i)
	{
		this->account_arr[i] = old_u.account_arr[i];
	}
}


Admin& Admin::operator=(const Admin & old_u){ //assignment operator overload
    cout << "AOO called" << endl;
	this->num_accounts = old_u.num_accounts;

	//free memory first
	if (this->account_arr != NULL){
		delete [] this->account_arr;
		this->account_arr = NULL;
	}
	//deep copy
	this->account_arr = new Account [this->num_accounts];
	for (int i = 0; i < this->num_accounts; ++i)
	{
		this->account_arr[i] = old_u.account_arr[i];
	}
	
	return *this;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


void Admin::load_account_arr(){
	ifstream fin;

    int num_duplicates = 0;
	int temp_size;
	string accounts_file = "accounts.txt";

    fin.open(accounts_file.c_str());
    fin >> temp_size;
	Account temp_account;
	Account * temp_arr = new Account [temp_size];
	for (int j = 0; j < temp_size; j++)
	{
		temp_arr[j].load_account(fin);
	}
	fin.close();



	for (int i = 0; i < temp_size; i++)
	{
		temp_account.set_account(temp_arr[i].get_username(), temp_arr[i].get_password());
		for (int k = i+1; k < temp_size; k++)
		{
			if (temp_account.get_username() == temp_arr[k].get_username())
			{
				num_duplicates++;
			}	
		}		
	}
	
	int size;
    fin.open(accounts_file.c_str());

    fin >> size;

	this->num_accounts = size-num_duplicates;

	this->account_arr = new Account [this->num_accounts];

	int index = 0;
	for (int i = 0; i < size; i++)
	{
		bool to_add = true;
		temp_account.load_account(fin);
		for (int k = i+1; k < size; k++)
		{
			if (temp_account.get_username() == temp_arr[k].get_username())
			{
				to_add = false;
				break;
			}
			
		}
		if (to_add == true)
		{
			this->account_arr[index].set_account(
						temp_arr[i].get_username(), temp_arr[i].get_password());
			index++;
		}
	}
	delete [] temp_arr;
	temp_arr = NULL;
	
}
/********************************************************************/


Account& Admin::search_by_username(string username){
	for (int i = 0; i < this->num_accounts; i++)
	{
		if (this->account_arr[i].get_username() == username)
		{
			cout << "Account found!!";
			cout << endl << "-------------" << endl;
			this->account_arr[i].print_account_info();
			cout << "-------------" << endl;
			return account_arr[i];
		}
	}
}







//GETTERS
void Admin::print_user_accounts(){
	cout << "Number of accounts: " << this->num_accounts << endl;
	cout << endl << "-------------" << endl;
	cout << endl;
	int index = 1; 
	for (int i = 0; i < this->num_accounts; i++)
	{
		cout << index << ". ";
		this->account_arr[i].print_account_info();
		cout << endl;
		index++;
	}
	cout << "-------------" << endl;
}



















void Admin::add_to_accounts(Account& account_to_add){
	Account * new_arr = new Account [(this->num_accounts+1)];
	int index = 0;
	for (int i = 0; i < this->num_accounts; i++)
	{
		new_arr[i] = this->account_arr[i];
			
	}
	new_arr[this->num_accounts] = account_to_add;
	
	
	this->num_accounts = this->num_accounts+1;
	
	
	delete [] this->account_arr;

	this->account_arr = new_arr;
	
	ofstream fout;
	fout.open("login.txt", ios::trunc);
	fout << this->num_accounts;
	for (int i = 0; i < this->num_accounts; i++)
	{
		fout << endl;
		fout << this->account_arr[i].get_username() << " ";
		fout << this->account_arr[i].get_password() << " ";
	}
}



void Admin::remove_from_accounts(int index_of_account_on_site){
	Account * new_arr = new Account [(this->num_accounts-1)];
	int index = 0;
	for (int i = 0; i < this->num_accounts; i++)
	{
		if (i != index_of_account_on_site)
		{
			new_arr[index] = this->account_arr[i];
			index++;
		}
	}
	this->num_accounts = this->num_accounts-1;
	delete [] this->account_arr;

	this->account_arr = new_arr;

	ofstream fout;
	fout.open("login.txt", ios::trunc);
	fout << this->num_accounts << endl;
	for (int i = 0; i < this->num_accounts; i++)
	{
		fout << this->account_arr[i].get_username() << " ";
		fout << this->account_arr[i].get_password() << " ";
		fout << endl;
	}
}
void Admin::print_accounts(){
	int index = 1; 
	for (int i = 0; i < this->num_accounts; i++)
	{
		cout << index << ". ";
		cout << this->account_arr[i].get_username();
		cout << endl;
		index++;
	}
	cout << endl;


}




//GETTERS
int Admin::get_num_accounts(){
	return this->num_accounts;
}
string Admin::get_username(int i){
	return this->account_arr[i].get_username();
}
string Admin::get_password(int i){
	return this->account_arr[i].get_password();
}








//SETTERS