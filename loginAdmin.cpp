#include"Bank.h"
void Bank::loginAdmin()
{
	system("cls");
	int choice;
	cout << "\n\\n\n\n\n\n\n\t\t\t\t\t------------------------------------Login----------------------------------------";
	cout << "\n\n\t\t\t\t\t1.Login";
	cout << "\n\t\t\t\t\t2.Register";
	cout << "\n\t\t\t\t\t3.Forgot Credentials";
	cout << "\n\t\t\t\t\t4.Exit";
back:
	cout << "\n\n\t\t\t\t\tSelect Your Option (1-4) :";
	cin >> choice;
	switch (choice)
	{

	case 1:
		login();
		break;
	case 2:
		createUser();
		break;
	case 3:
		forgotUser();
		break;
	case 4:
		cout << "\n\t\t\t\t\tThanks for using the login page";
		break;
	default:
		cout << "\n\t\t\t\t\tSorry Wrong choice";
		goto back;
	
		
	}

}