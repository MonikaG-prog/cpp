#include"Bank.h"

int Bank::getId(sqlite3* db, sqlite3_stmt* stmt)
{
	sqlite3_prepare(db, "select * from account where accno=(select MAX(accno) from account);", -1, &stmt, NULL);
	sqlite3_step(stmt);
	int id = sqlite3_column_int(stmt, 0);

	return id;

}
int Bank::getlogId(sqlite3* db, sqlite3_stmt* stmt)
{
	sqlite3_prepare(db, "select * from login where logid=(select MAX(logid) from login);", -1, &stmt, NULL);
	sqlite3_step(stmt);
	int logid = sqlite3_column_int(stmt, 0);

	return logid;

}
int Bank::gettransId(sqlite3* db, sqlite3_stmt* stmt)
{

	sqlite3_prepare(db, "select MAX(transid) from transaction1;", -1, &stmt, NULL);
	sqlite3_step(stmt);
	int logid = sqlite3_column_int(stmt, 0);

	return logid;

}