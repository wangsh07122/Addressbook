#pragma once
#include<person.h>
class Colleague :public Person {
public:
	string company;
	Colleague(string a, MyDate b, string c, string d, string e) :Person(a, b, c, d), company(e) {};
	string getType()const { return "Colleague"; }
	string getExtra()const { return company; }
	string getFileName()const { return "AddressBook2.txt"; }
	string birthdaymsg() { return "¹¤×÷Ë³Àû£¡"; }
	void setExtra(string extra) { company = extra; return; }
};