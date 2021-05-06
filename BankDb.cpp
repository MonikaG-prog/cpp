#include"Bank.h"
void Bank::creaDatabase()
{
	sqlite3_open("Bank.db",&db);

	int rc = sqlite3_exec(db, "create table if not exists account(accno int ,firstname varchar(100),lastname varchar(100),type varchar(10),address varchar(10),mobno varchar(10),cash int );", NULL, NULL, &err);
	if (rc != SQLITE_OK)
	{
		cout << "Error:" << err;
	}
	int rc1= sqlite3_exec(db, "create table if not exists login(logid int ,username varchar(20),passwd varchar(20),utype varchar(20));", NULL, NULL, &err);
	if (rc1 != SQLITE_OK)
	{
		cout << "Error :" << err;
	}
	int rc2 = sqlite3_exec(db, "create table if not exists transaction1(transid int,accno int ,firstname varchar(100),lastname varchar(100),type varchar(10),trantype varchar(10),cash int,datet varchar(20));", NULL, NULL, &err);
	if (rc2 != SQLITE_OK)
	{
		cout << "Error :" << err;
	}
}















