#include"Bank.h"
void Bank::forgotUser()
{
	int ch;
	int result=0;
	string username,s;
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------Forgotten? We're here for your help-----------------------------------" << endl;
	cout << "\n\n\t\t\t\t\t\t1.Search your account by username";
	cout<<endl<< "\t\t\t\t\t\t2.Search your account by password";
	cout << endl << "\t\t\t\t\t\t3.Main Menu";
	cout << endl << "\n\t\t\t\t\t\tEnter your choice";
	cin >> ch;
	switch (ch)
	{
	case 1:
		
		cout << "\t\t\t\t\t\tEnter your remembered username:";
		cin >> username;

		 s = "Select passwd from login where username='" + username + "';";
		result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int passwd = sqlite3_column_int(stmt, 0);
				cout << "\t\t\t\t\t\tYour account is found"<<endl;
				cout << "\t\t\t\t\t\tYour username is " << uname;
				cout << "\n\t\t\t\t\t\tYour password is " << passwd;
				cin.get();
				cin.get();
				loginAdmin();

			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t" << "Account Doesnot exists!!Try Another Way";
				cin.get();
				cin.get();
				loginAdmin();

			}


		}
		break;
	case 2:
		cout << "\t\t\t\t\t\tEnter your remembered Password:";
		cin >> passwd;

		s = "Select username from login where passwd='" + passwd + "';";
	    result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int passwd = sqlite3_column_int(stmt, 0);
				cout << "\t\t\t\t\t\tYour account is found" << endl;
				cout << "\t\t\t\t\t\tYour username is " << uname;
				cout << "\n\t\t\t\t\t\tYour Password is " << passwd;
				cin.get();
				
				loginAdmin();

			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t" << "Account Doesnot exists!!Try Another Way";

			}


		}
		break;

	case 3:
		loginAdmin();
		break;

	}

}