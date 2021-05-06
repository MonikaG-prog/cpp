
#include"Bank.h"
void Bank::createUser()
{
	uid = getlogId(db, stmt);

	std::cout << endl << "\t\t\t\t\t\tYour  id. :" << uid + 1 << endl;
	AcceptAdmin();

	std::string sql = "insert into login values(" + to_string(uid + 1) + ",'" + uname + "','" + passwd + "','admin')";
	
	int rc1 = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc1 != SQLITE_OK)
	{
		cout << endl << "Error:" << err;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tYour Account is created successfully!..";
	}
	cout << "\n\n\t\t\t\t\t\t+------------------------------------------------+";
	cout << endl << endl << "\t\t\t\t\t\tPlease remember account no for further operation";
	cout << endl << "\n\t\t\t\t\t\t+------------------------------------------------+";

}