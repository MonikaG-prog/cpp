#include"Bank.h"
void Bank::perData()
{
	id = getId(db, stmt);
	transid = gettransId(db, stmt);
	time_t t;
	//struct tm nowLocal;
	time(&t);
	char *current_time = ctime(&t);
	
	std::cout << endl << "\t\t\t\t\t\tYour account No. :" << id + 1 << endl;
	Accept();

	std::string sql = "insert into account values(" + to_string(id + 1) + ",'" + firstName + "','" + lastname + "','" + type + "','" + address + "','" + contact + "'," + to_string(cash) + ")";
	std::string sql1 = "insert into transaction1 values(" +to_string(transid+1)+","+ to_string(id + 1) + ",'" + firstName + "','" + lastname + "','" +type + "','credit'," + to_string(cash) + ",'"+ current_time +"')";
	int rc1 = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc1 != SQLITE_OK)
	{
		cout << endl << "Error:" << err;
	}
	else
	{
		int rc2 = sqlite3_exec(db, sql1.c_str(), NULL, NULL, &err);
		if (rc2 != SQLITE_OK)
		{
			cout << endl << "Error:" << err;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\tYour Account is created successfully!..";
		}
	}
	int rc2 = sqlite3_exec(db, sql1.c_str(), NULL, NULL, &err);
	if (rc2 != SQLITE_OK)
	{
		cout << endl << "Error:" << err;
	}
	



	cout << "\n\n\t\t\t\t\t\t+------------------------------------------------+";
	cout << endl << endl << "\t\t\t\t\t\tPlease remember account no for further operation";
	cout << endl << "\n\t\t\t\t\t\t+------------------------------------------------+";

}  




