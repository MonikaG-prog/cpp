#include"Bank.h"

int  Bank::showAdminMenu()
{
	char ch;
	do
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t**************************************************************************" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\tMAIN MENU" << endl;
		cout << "\n\t\t\t\t\t**************************************************************************" << endl;
		cout << "\n\n\t\t\t\t\t\t1.New Account" << endl;
		cout << "\n\n\t\t\t\t\t\t2.All Account Holder List" << endl;
		cout << "\n\n\t\t\t\t\t\t3.Modify an account" << endl;
		cout << "\n\n\t\t\t\t\t\t4.Balance Enquiry" << endl;
		cout << "\n\n\t\t\t\t\t\t5.Transaction Details" << endl;
		cout << "\n\n\t\t\t\t\t\t6.Close Account" << endl;
		cout << "\n\n\t\t\t\t\t\t7.Exit" << endl;
		system("Color 0B");
		cout << endl << "\n\n\tSelect Your Option(1-7): ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			std::cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------NEW ACCOUNT ENTRY FORM-----------------------------------" << endl;
			Bank::perData();
			break;
		case '2':
			Bank::show();
			break;
		case '3':
			int uid;
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------MODIFY RECORD-----------------------------------" << endl;
			cout << "\n\n\n\t\t\t\t\t\t*****************************************************\n";
			cout << "\n\t\t\t\t\t\t\tEnter the account No. :";
			while (!(cin >> uid))
			{
				cout << "\n\n\t\t\t\t\t\tPlease Enter  your account no ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			Bank::update(uid);
			break;
		case '4':
			int sid;
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------BALANCE ENQUIRY-----------------------------------" << endl;
			cout << "\n\t\t\t\t\t\t\tEnter the account No. :";
			while (!(cin >> sid))
			{
				cout << "\n\n\t\t\t\t\t\tPlease Enter  your account no ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			Bank::search(sid);
			break;
		case '5':
			Bank::transactionDetail();
			break;
		case '6':
			Bank::del();
			break;
		case '7':
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t*******************************************************************";
			cout << "\n\t\t\t\t\t\t\t\tThanks for using Bank Management System";
			cout << "\n\n\t\t\t\t\t\t*******************************************************************";

			exit(0);
			break;
		default:cout << "\a";
			break;
		}
		cin.ignore();
		cout << endl << "Please press enter to continue";
		cin.get();

	} while (ch != 7);
	return 0;
}