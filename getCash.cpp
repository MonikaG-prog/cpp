#include"Bank.h"

int Bank::getCash(sqlite3* db, sqlite3_stmt* stmt, int tid)
{
	string sql = "SELECT cash from account where accno=" + to_string(tid) + ";";
	sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);//preparing the statement
	sqlite3_step(stmt);//executing the statement
	int oldcash = sqlite3_column_int(stmt, 0);///reading the 1st column of the result

	return oldcash;

}