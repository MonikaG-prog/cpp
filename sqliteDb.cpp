#include<iostream>
#include"Bank.h"
using namespace std;
int main()
{
	Bank b;
	char ch;
	b.creaDatabase();
	b.DisplayFormat();
	do
	{
		std::system("cls");
		std::cout << "\n\n\n\n\n\n\t\t\t\t\t**************************************************************************" << endl;
		std::cout << "\n\t\t\t\t\t\t\t\t\tMAIN MENU" << endl;
		std::cout << "\n\t\t\t\t\t**************************************************************************" << endl;
		std::cout << "\n\n\t\t\t\t\t\t1.Admin User" << endl;
		std::cout << "\n\n\t\t\t\t\t\t2.Customer" << endl;
		std::cout << "\n\n\t\t\t\t\t\t3.Exit" << endl;
		std::system("Color 0B");
		std::cout << endl << "\n\n\tSelect Your Option(1-3): ";
		std::cin >> ch;
		std::system("cls");
		switch (ch)
		{
		case '1':b.loginAdmin();
			     break;
		case '2':b.showMenu();
				break;
		case '3':
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t*******************************************************************";
			std::cout << "\n\t\t\t\t\t\t\t\tThanks for using Bank Management System";
			std::cout << "\n\n\t\t\t\t\t\t*******************************************************************";
			exit(0);
			break;
		default:std::cout << "\a";
			break;
		}
		std::cin.ignore();
		std::cout << endl << "\n\n\t\t\t\t\t\tSelect Your Option between(1-3)";
		std::cin.get();

	} while (ch != 3);

	std::system("PAUSE");
	return 0;
	   	  
	
}