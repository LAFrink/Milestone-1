CC=g++
exe_file=run

$(exe_file): Main.cpp account_login.o account_user_list.o account_info.o user_menu.o user_cur_info.o
	$(CC) Main.cpp account_login.o account_user_list.o account_info.o user_menu.o user_cur_info.o -o $(exe_file)
account_login.o: account_login.cpp account_login.h 
	$(CC) -c account_login.cpp
account_user_list.o: account_user_list.cpp account_user_list.h
	$(CC) -c account_user_list.cpp
account_info.o: account_info.cpp account_info.h
	$(CC) -c account_info.cpp
user_menu.o: user_menu.cpp user_menu.h
	$(CC) -c user_menu.cpp
user_cur_info.o: user_cur_info.cpp user_cur_info.h
	$(CC) -c user_cur_info.cpp

clean:
	rm -f *.o $(exe_file)