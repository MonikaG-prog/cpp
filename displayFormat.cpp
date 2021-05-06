#include"Bank.h"
/*Display Format*/
void Bank::DisplayFormat()
{

	time_t t;
	//struct tm nowLocal;
	time(&t);
	char *current_time = ctime(&t);
	//ClrScrn(FOREGROUND_RED)
	cout << endl << endl;
	//SetConsoleCursorPosition();
	std::cout << std::right << std::setw(160) << current_time << std::endl;
	cout << "\t\t\t===============================================================================================" << endl;
	cout << "\t\t\t***********************************WelCome to Bank System**************************************" << endl;
	cout << "\t\t\t===============================================================================================" << endl;
	cin.get();
}