#include"Bank.h"

bool Bank::ValidationMbNo(string contact)
{
	bool iscorrect = false;
	regex integer_expr("(\\+|-)?[[:digit:]]+");
	if ((regex_match(contact, integer_expr)) && (contact.size() == 10))
	{
		iscorrect = true;
	}

	return iscorrect;
}
bool Bank::ValidationCash(double amt, string &type)
{
	bool isCorrect = false;
	if ((type == "SAVING") && (amt < 500))
		isCorrect = true;
	if ((type == "CURRENT") && (amt < 1000))
		isCorrect = true;
	return isCorrect;
}


bool Bank::validationType(string &type)
{
	bool isType = false;
	if ((type == "CURRENT") || (type == "SAVING"))
	{
		isType = true;
	}
	return isType;
}


bool Bank::ValidationCh(char ch)
{
	bool isCorrect = false;

	if ((ch == '1') || (ch == '2'))
	{
		isCorrect = true;
	}
	return isCorrect;
}

bool Bank::ValidationChd(char ch)
{
	bool isCorrect = false;

	if ((ch == 'Y') || (ch == 'N'))
	{
		isCorrect = true;
	}
	return isCorrect;
}