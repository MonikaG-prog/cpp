#include"Bank.h"
void Bank::login()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------LOGIN FORM-----------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\tUsername :";
	cin >> uname;
	cout << "\n\t\t\t\t\t\t\tPassword :";
	cin >> passwd;

	string s = "Select * from login where username='" +uname + "' and passwd='"+passwd+"';";
	int ret_code = 0;


	int result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
	if (result == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			showAdminMenu();
		}
		else
		{

			cout << "\n\t\t\t\t\t\t\t" << "Account Doesnot exists!!Try again";
			cin.get();
			cin.get();
			loginAdmin();
		}


	}


}