#include"Bank.h"
/*Display Specific Account Information*/

int Bank::searchSpecific(int sid)
{

	char * firstname; char * lastname; char * address; char * contact; char * type;

	//int count = getId(db, stmt);
	string s = "Select * from account where accno=" + to_string(sid) + ";";

	int ret_code = 0;


	int result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
	if (result == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			//while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW)
			//{
			id = sqlite3_column_int(stmt, 0);
			//firstname = (char*)sqlite3_column_text(stmt, 1);
			//lastname = (char*)sqlite3_column_text(stmt, 2);
			//type = (char*)sqlite3_column_text(stmt, 3);
			//address = (char*)sqlite3_column_text(stmt, 4);
			//contact = (char*)sqlite3_column_text(stmt, 5);
			cash = sqlite3_column_double(stmt, 6);
			cout << "\n\n\t\t\t\t\t\t Your A/C XXX"+to_string(sid)+" Balance is:"+to_string(cash)+"CR";
			//cout << "\n\t\t\t\t\t" << sid << setw(10) << " " << firstname << " " << lastname << setw(20) << contact << setw(25) << address << setw(15) << type << setw(5) << cash << endl;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t" << "Account Doesnot exists";
			return -1;
		}

	}
	return 0;
}
