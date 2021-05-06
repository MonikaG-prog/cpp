#include"Bank.h"

void Bank::AcceptAdmin()
{
	string chpasswd;

	std::cout << "\n\t\t\t\t\t\tEnter the username: ";
	std::cin.ignore();
	std::cin >> uname;

	std::cout << "\n\t\t\t\t\t\tEnter the password";
	std::cin >> passwd;
	
}

	//logid int, username varchar(20), passwd varchar(20), utype varchar(20)

