#pragma once
#pragma once
#include<sstream>
#include<iostream>
#include<fstream>

#include<string>
#include<iomanip>
#include<cctype>
#include<regex>
#include<cstring>
#include"sqlite\sqlite3.h"
using namespace std;

class  Bank
{
public:
	int id,uid,transid;
	string firstName, lastname, address,uname,passwd,utype;
	string contact;
	string type;
	double cash;
	
	char* err;
	sqlite3* db;
	sqlite3_stmt* stmt;
	void convertUpper(string &type);
	int showMenu();
	void perData();
	void show();
	void update(int uid);
	int search(int sid);
	void transction();
	double dep();
	void del();
	void DisplayFormat();
	int getId(sqlite3* db,	sqlite3_stmt* stmt);
	int getlogId(sqlite3* db, sqlite3_stmt* stmt);
	int gettransId(sqlite3* db, sqlite3_stmt* stmt);
	int getCash(sqlite3* db, sqlite3_stmt* stmt,int tid);
	void Accept();
	void AcceptAdmin();
	void creaDatabase();
	void createUser();
	int searchSpecific(int sid);
	
	// Admin part
	void loginAdmin();
	void login();
	void forgotUser();
	int showAdminMenu();
	void transactionDetail();
	
	//Validation
	bool ValidationMbNo(string contact);
	bool ValidationCh(char ch);
    bool validationType(string &type);
	bool ValidationCash(double amt, string& type);
	bool ValidationChd(char ch);
};