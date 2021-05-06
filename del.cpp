#include"Bank.h"
void Bank::del()
{

	int did;
	char closeAcc;
	char ch;
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------REMOVE ACCOUNT-----------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t**************************************";
	cout << "\n\t\t\t\t\t\tPress 1 to Close specific account" << endl;
	cout << "\t\t\t\t\t\tPress 2 to Close all record" << endl;
	cout << "\n\t\t\t\t\t\t**************************************";
	back3:
	cout << "\n\t\t\t\t\t\tEnter Choice(1/2) : ";
	cin.clear();
	cin >> ch;
	if (!ValidationCh(ch))
	{
		cout << "\n\t\t\t\t\t\tPlease enter corrrect choice(1/2)";
		goto back3;
	}
	switch (ch)
	{
	case '1':
		sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
		cout << "\n\t\t\t\t\t\t\tEnter the account No. :";
		while (!(cin >> did))
		{
			cout << "\n\n\t\t\t\t\t\tPlease Enter  your account no ";
			cin.clear();
			cin.ignore(22, '\n');
		}
		if (search(did) == -1);
		else
		{
		back4:

			cout << "\n\t\t\t\t\t\t\tAre you sure to close an account?(Y/N)";
			cin >> closeAcc;
			closeAcc = toupper(closeAcc);
			if (!ValidationChd(closeAcc))
			{
				cout << "\n\t\t\t\t\t\tPlease enter corrrect choice(Y/N)";
				goto back4;
			}


			if (closeAcc == 'Y')
			{

				string sql = "delete from account where accno=" + to_string(did) + ";";
				sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);//preparing the statement
				sqlite3_step(stmt);//executing the statement
				sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
			}
			break;
	case '2':
		cout << "\n\t\t\t\t\t\t\tAre you sure to close an account?(Y/N)";
		cin >> closeAcc;
		if (toupper(closeAcc) == 'Y')
		{
			sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
			string sql = "delete  from account ";
			sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);//preparing the statement
			sqlite3_step(stmt);//executing the statement
			sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
		}
		break;

		}
	}
}

