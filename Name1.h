#pragma once
#include<iostream>
#include<string>
using namespace std;
class Name1
{
public:
	Name1();
	string firstName, lastname, address;
	int id;
	static int current_id;
	string type;
	string contact;
	double cash;
	void setName(int id, string firstName, string lastname, string type, string address, string contact, double cash);
	void getName();

}; 
