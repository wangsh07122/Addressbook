#pragma once
#include<person.h>
class Relative :public Person {
public:
	string relation;
	Relative(string a, MyDate b, string c, string d, string e) :Person(a, b, c, d), relation(e) {};
	string getType()const { return "Relative"; }
	string getExtra()const { return relation; }
	string getFileName()const { return "AddressBook4.txt"; }
	string birthdaymsg() { return "…ÌÃÂΩ°øµ£°"; }
	void setExtra(string extra){ relation = extra; return; }
};