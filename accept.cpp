#include"Bank.h"
void Bank::Accept()
{

	std::cout << "\n\t\t\t\t\t\tEnter the Name of the account Holder(First Name LastName): ";
	std::cin.ignore();
	std::cin >> firstName >> lastname;
back2:
	std::cout << "\n\t\t\t\t\t\tEnter the type of account(Current/Saving):";
	std::cin >> type;
	transform(type.begin(), type.end(), type.begin(), ::toupper);
	if (!validationType(type))
	{
		std::cout << "\n\t\t\t\t\t\tPlease enter correct account type(Current/Saving)";
		goto back2;
	}
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
back1:
	if (type == "SAVING")
	{
		cout << "\n\t\t\t\t\t\tEnter initial amount greater or equal to 500:";
	}
	else if (type == "CURRENT")
	{
		cout << "\n\t\t\t\t\t\tEnter initial amount greater or equal to 1000:";
	}
	while (!(cin >> cash))
	{
		cout << "\n\n\t\t\t\t\t\tPlease Enter  your cash  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	if (ValidationCash(cash, type))
	{
		goto back1;
	}


}
