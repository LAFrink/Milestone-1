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
#include "account_login.h"
#include "user_cur_info.h"
#include "user_menu.h"

using namespace std;

int main()
{
	Login s;
	bool run_login = true;
	run_login = s.site_welcome();
	if (run_login == true)
	{
		string user_file = s.get_user_file();
		History luke = History(user_file);
		luke.user_welcome();
	}
	
	


	
	return 0;
}