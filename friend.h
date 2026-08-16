#pragma once
#include<person.h>
class Friend :public Person {
public:string place;
	  Friend(string a,MyDate b,string c,string d,string e):Person(a,b,c,d),place(e){}
	  string getType()const { return "Friend"; }
	  string getExtra()const { return place; }
	  string getFileName()const { return "AddressBook3.txt"; }
	  string birthdaymsg() { return "Éú»îÓä¿ì£¡"; }
	  void setExtra(string extra) { place = extra; return; }
};