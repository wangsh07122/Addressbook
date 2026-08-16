#pragma once
#include<person.h>
class Student :public Person {
public:string school;
	  Student(string a, MyDate b, string c, string d, string e) :Person(a, b, c, d), school(e) {};
	  string getType()const { return "Student"; }
	  string getExtra()const { return school; }
	  string getFileName()const { return "AddressBook1.txt"; }
	  string birthdaymsg() { return "Ñ§Ï°½ø²½£¡"; }
	  void setExtra(string extra) { school = extra; return; }
};