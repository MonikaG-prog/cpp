#include"Bank.h"
void Bank::transactionDetail()
{

	
	    char* type;
		char *firstname; char *lastname; char *transtype; char *datet;
	
		int sid,tid;

		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------TRANSACTION DETAIL-----------------------------------" << endl;
		
		cout << "\n\t\t\t\t\t\t\tEnter the account No. :";
		while (!(cin >> sid))
		{
			cout << "\n\n\t\t\t\t\t\tPlease Enter  your account no ";
			cin.clear();
			cin.ignore(22, '\n');
		}
		cout << "\n\t\t\t\t=======================CUSTOMER INFORMATION=============================================\n";
		

		int gett = search(sid);
		cout << "\n\n\t\t\t\t=========================================================================================\n";
		cout << "\t\t\t\t\t TRANSCATION TYPE      BALANCE       DATE ";
		cout << "\n\t\t\t\t=========================================================================================\n";
		if (gett == -1);
		else
		{


			//int count = getId(db, stmt);
			string s = "Select * from transaction1 where accno=" + to_string(sid) + ";";
			

			int ret_code = 0;


			int result = sqlite3_prepare_v2(db, s.c_str(), -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				if (sqlite3_step(stmt) == SQLITE_ROW)
				{
					while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW)
					{
						tid = sqlite3_column_int(stmt, 0);
						id = sqlite3_column_int(stmt, 1);
						firstname = (char*)sqlite3_column_text(stmt, 2);
						lastname = (char*)sqlite3_column_text(stmt, 3);
						type = (char*)sqlite3_column_text(stmt, 4);
						transtype = (char*)sqlite3_column_text(stmt, 5);
						cash = sqlite3_column_double(stmt, 6);
						datet = (char*)sqlite3_column_text(stmt, 7);
						cout << "\n\t\t\t\t\t"  << transtype << setw(30) << to_string(cash) << setw(30) << datet << endl;
					}
				}
				else
				{
					cout << "\n\t\t\t\t\t\t\t" << "Account Doesnot exists";

				}

			}



		}


}