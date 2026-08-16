#pragma once
#include<string>
#include<ctime>//时间获取
using namespace std;
class Person {
	
public:
	struct MyDate {
		int y, m, d;
		MyDate(int a = 0, int b = 0, int c = 0) :y(a), m(b), d(c) {}
	};
	string name;
	MyDate birth;
	string tel;
	string email;
	Person(string a, MyDate b, string c, string d) :name(a), birth(b), tel(c), email(d) {};
	virtual string getType() const = 0;
	virtual string getExtra() const  = 0;
	virtual string getFileName()const = 0;
	virtual void setExtra(string extra) = 0;
	virtual string birthdaymsg() = 0;
	virtual ~Person() {};//虚析构，防止内存泄露
};