#pragma once
#include<person.h>
#include<vector>
#include<algorithm>
using namespace std;
class AddressBook {
public:
	//添加联系人
	void addPerson(Person* p);
	//保存到文件
	void saveToFile() const;
	//读取文件
	void loadFromFile();
	//获取所有人
	vector<Person*> getAllPerson()const;
	//按姓名查找
	vector<Person*>searchByName(string name) const;
	//删除联系人
	bool deletePerson(string name, string type);
	//修改信息
	Person* searchByNameandType(string name, string type);
	//按类别获取
	vector<Person*> getByType(string type) const;
	//按姓名排序，从小到大
	void sortByName();
	//按生日排序，从早到晚
	void sortByBirthday();
	//统计给定月份出生人数
	int countByMonth(int month)const;
	//获取现在时间
	void getToday(int& outYear,int& outMonth, int& outDay)const;
	//查找未来五天内生日的人
	vector<Person*>findBirthIn5DaysAuto()const;
	//生成生日信息
	void generateBirthdayMsg(Person* P)const;
	//生成五天内生日所有人的信息
	void generateAllBirthdayMsgs()const;
	//将生日转化为日期
	string getWeekDay(int year, int month, int day)const;
	~AddressBook();
private:
	vector<Person*>list;
};