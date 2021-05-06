#include"Bank.h"

/*Used For updating the record*/
void Bank::update(int uid)
{
	try
	{
		int found = search(uid);
		if (found == -1);
		else
		{
			cout << "\n\n\n\t\t\t\t\t\t*****************************************************\n";
			std::cout << endl << "\t\t\t\t\t\tYour account No. :" << id << endl;
			//Accept();

			std::cout << "\n\t\t\t\t\t\tEnter the Name of the account Holder(First Name LastName): ";
			std::cin.ignore();
			std::cin >> firstName >> lastname;
			std::cout << "\n\t\t\t\t\t\tAddress : ";
			std::cin.ignore();
			getline(std::cin, address);
		back:
			std::cout << "\n\t\t\t\t\t\tMobile No :";
			cin >> contact;
			if (!ValidationMbNo(contact))
			{
				cout << "\n\t\t\t\t\t\tPlease enter corrrect mobile number(It should be 10 digit numeric number.)";
				goto back;
			}
			sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
			std::string sql = "update account set firstname='" + firstName + "',lastname='" + lastname + "',type='" + type + "',address='" + address + "',mobno='" + contact + " where accno=" + to_string(uid);
			//	cout << sql;
			int rc1 = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
			sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);

			cout << "\n\n\t\t\t\t\t\tYour Account is Updated Successfully!..";

		}

	}
	catch (exception e)
	{
		cout << e.what();
	}
}

