#include"Bank.h"
void Bank::show()
{
	int id, cash, count;
	char * firstname; char * lastname; char * address; char * contact; char * type;
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------ALL ACCOUNT HOLDER LIST-----------------------------------" << endl;
	cout << "\t\t\t\t====================================================================================================\n";
	cout << "\t\t\t\t\tA/C NO.		NAME          MOBILE NO          ADDRESS              TYPE        BALANCE\n";
	cout << "\t\t\t\t====================================================================================================\n";

	count = getId(db, stmt);

	sqlite3_prepare(db, "SELECT * from account;", -1, &stmt, NULL);
	int ret_code = 0;
	while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		id = sqlite3_column_int(stmt, 0);
		firstname = (char*)sqlite3_column_text(stmt, 1);
		lastname = (char*)sqlite3_column_text(stmt, 2);
		type = (char*)sqlite3_column_text(stmt, 3);
		address = (char*)sqlite3_column_text(stmt, 4);
		contact = (char*)sqlite3_column_text(stmt, 5);
		cash = sqlite3_column_int(stmt, 6);

		cout << "\n\t\t\t\t\t" << id << setw(10) << " " << firstname << " " << lastname << setw(20) << contact << setw(25) << address << setw(15) << type << setw(5) << cash << endl;
	}



}