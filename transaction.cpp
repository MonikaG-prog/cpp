#include"Bank.h"
void Bank::transction()
{
	int tid,transid;
	char ch;
	double ncash;
	std::string sql, sql2;
	int rc1, rc2;

	time_t t;
	//struct tm nowLocal;
	time(&t);
	char *current_time = ctime(&t);
	transid = gettransId(db, stmt);

	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------ACCOUNT TRANSACTION FORM-----------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\tEnter the account No. : ";
	cin >> tid;
	double oldcash = getCash(db, stmt, tid);
	cout << "\n\n\n\t\t\t\t\t\t\t----ACCOUNT STATUS----\n";
	int tid1 = search(tid);
	if (tid1 == -1);
	else
	{
		//go to the all values


		string s = "Select * from account where accno=" + to_string(tid) + ";";

		int ret_code = 0;


		int result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				//while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW)
				//{
				id = sqlite3_column_int(stmt, 0);
				firstName = (char*)sqlite3_column_text(stmt, 1);
				lastname = (char*)sqlite3_column_text(stmt, 2);
				type = (char*)sqlite3_column_text(stmt, 3);
			}

			cout << "\n\t\t\t\t\t\t**************************************";
			cout << "\n\t\t\t\t\t\tPress 1 to Deposit" << endl;
			cout << "\t\t\t\t\t\tPress 2 to Withdraw" << endl;
			cout << "\n\t\t\t\t\t\t**************************************";
		back3:
			cout << "\n\t\t\t\t\t\tEnter Choice(1/2) : ";
			cin >> ch;
			if (!ValidationCh(ch))
			{
				cout << "\n\t\t\t\t\t\tPlease enter corrrect choice(1/2)";
				goto back3;
			}
			switch (ch)
			{
			case '1':
				cout << "\t\t\t\t\t\tYou have selected for Deposit transaction";
				sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
				cout << "\n\t\t\t\t\t\tEnter the amount to be deposited :";
				while (!(cin >> ncash))
				{
					cout << "\n\n\t\t\t\t\t\tPlease Enter  your cash ";
					cin.clear();
					cin.ignore(22, '\n');
				}
				sql = "update account set cash=" + to_string(oldcash + ncash) + " where accno=" + to_string(tid);

				//for transaction detail table
				
				sql2 = "insert into transaction1 values(" + to_string(transid + 1) + "," + to_string(tid) + ",'" + firstName + "','" + lastname + "','" + type + "','credit'," + to_string(oldcash + ncash) + ",'" + current_time + "')";


				rc1 = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);

				rc2 = sqlite3_exec(db, sql2.c_str(), NULL, NULL, &err);
				sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
				cout << "\n\n\t\t\t\t\t\tYour Account is Updated Successfully!..";

				cout << "\n\t\t\t\t\t\tAvailable Balance :" << to_string(oldcash + ncash) << endl;
				break;
			case '2':
				cout << "\t\t\t\t\t\tYou have selected for Withdraw transaction";
			back:
				sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
				cout << "\n\t\t\t\t\t\tEnter the amount  to be withdraw ";
				while (!(cin >> ncash))
				{
					cout << "\n\n\t\t\t\t\t\tPlease Enter  your cash ";
					cin.clear();
					cin.ignore(22, '\n');
				}

				if ((type=="SAVING") && (ncash == oldcash))
				{
					cout << "\t\t\t\t\t\t You cannot Minimum balance should be 500,your Available balance is : " << to_string(oldcash) << endl;

					goto back;
				}
				else if ((type == "CURRENT") && (ncash == oldcash))
				{
					cout << "\t\t\t\t\t\tMinimum balance should be 1000,your Available balance is : " <<to_string(oldcash) << endl;

					goto back;
				}
				else if (ncash > oldcash)
				{
					cout << "\t\t\t\t\t\tYou have insufficient Balance :" << to_string(oldcash) << endl;

					goto back;
				}
				


				sql = "update account set cash=" + to_string(oldcash - ncash) + " where accno=" + to_string(tid);
				rc1 = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);

				//for transaction table
				sql2 = "insert into transaction1 values(" + to_string(transid + 1) + "," + to_string(tid) + ",'" + firstName + "','" + lastname + "','" + type + "','debit'," + to_string(oldcash - ncash) + ",'" + current_time + "')";

				rc2 = sqlite3_exec(db, sql2.c_str(), NULL, NULL, &err);


				sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
				cout << endl << "\n\t\t\t\t\t\tAvailable Balance  " << to_string(oldcash - ncash) << endl;
				break;
			default:
				cout << "\t\t\t\t\t\tInvalid Input" << endl;
				break;
			}

		}
	}
}