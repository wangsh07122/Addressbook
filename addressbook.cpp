#include<addressbook.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include <student.h>
#include <colleague.h>
#include <friend.h>
#include <relative.h>
using namespace std;
void AddressBook::addPerson(Person*p) {
	list.push_back(p);
}
//将字符串间隔区分
vector<string> split(const string& s, char ch) {
	vector<string>res;
	stringstream ss;
	ss << s;
	string part;
	while (getline(ss, part, ch)) {
		res.push_back(part);
	}
	return res;
}
void AddressBook::saveToFile() const{
	ofstream f1("AddressBook1.txt"); f1.close();
	ofstream f2("AddressBook2.txt"); f2.close();
	ofstream f3("AddressBook3.txt"); f3.close();
	ofstream f4("AddressBook4.txt"); f4.close();
	for (int i = 0; i < list.size(); i++) {
		ofstream out(list[i]->getFileName(),ios::app);//用ios::app，追加模式，防止每写一次都把前面清空
		out << list[i]->name << "," 
			<< to_string(list[i]->birth.y) << "-" << to_string(list[i]->birth.m) << "-" << to_string(list[i]->birth.d) << "," 
			<< list[i]->tel<<"," 
			<< list[i]->email<<","
			<< list[i]->getExtra() << endl;
		out.close();
	}
}
void AddressBook::loadFromFile() {
	//先清除剩余内容
	for (int i = 0; i < list.size(); i++) {
		delete list[i];
	}
	list.clear();//清除list中的指针
	//读取同学
	ifstream instu("AddressBook1.txt");
	string line;
	while (getline(instu, line)) {
		vector<string>res=split(line,',');
		if (res.size() < 5) { continue; }//若元素不足五个，跳过，防止后面出现数组越界
		vector<string>date = split(res[1], '-');
		int y = stoi(date[0]);//将字符串转化为整型
		int m = stoi(date[1]);
		int d = stoi(date[2]);
		Person::MyDate birth(y, m, d);
		addPerson(new Student(res[0], birth, res[2], res[3], res[4]));
	}
	instu.close();
	//读取同事
	ifstream incol("AddressBook2.txt");

	while (getline(incol, line)) {
		vector<string>res = split(line, ',');
		if (res.size() < 5) { continue; }//若元素不足五个，跳过，防止后面出现数组越界
		vector<string>date = split(res[1], '-');
		int y = stoi(date[0]);//将字符串转化为整型
		int m = stoi(date[1]);
		int d = stoi(date[2]);
		Person::MyDate birth(y, m, d);
		addPerson(new Colleague(res[0], birth, res[2], res[3], res[4]));
	}
	incol.close();
	//读取朋友
	ifstream infri("AddressBook3.txt");
	
	while (getline(infri, line)) {
		vector<string>res = split(line, ',');
		if (res.size() < 5) { continue; }//若元素不足五个，跳过，防止后面出现数组越界
		vector<string>date = split(res[1], '-');
		int y = stoi(date[0]);//将字符串转化为整型
		int m = stoi(date[1]);
		int d = stoi(date[2]);
		Person::MyDate birth(y, m, d);
		addPerson(new Friend(res[0], birth, res[2], res[3], res[4]));
	}
	infri.close();
	//读取亲戚
	ifstream inrel("AddressBook4.txt");
	
	while (getline(inrel, line)) {
		vector<string>res = split(line, ',');
		if (res.size() < 5) { continue; }//若元素不足五个，跳过，防止后面出现数组越界
		vector<string>date = split(res[1], '-');
		int y = stoi(date[0]);//将字符串转化为整型
		int m = stoi(date[1]);
		int d = stoi(date[2]);
		Person::MyDate birth(y, m, d);
		addPerson(new Relative(res[0], birth, res[2], res[3], res[4]));
	}
	inrel.close();
}
vector<Person*>AddressBook::getAllPerson()const {
	return list;
}
vector<Person*>AddressBook:: searchByName(string name) const{
	vector<Person*>re;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->name == name) {
			re.push_back(list[i]);
		}
	}
	return re;
}
bool AddressBook::deletePerson(string name, string type) {
	bool find = false;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->name == name && list[i]->getType() == type) { delete list[i];//先删除指针指向的内容
		list.erase(list.begin() + i);//再删除指针
		find = true;
		break;//不加break的话数组索引会因为删除移动，最后越界崩溃
		}
	}
	return find;
}
Person* AddressBook::searchByNameandType(string name, string type) {
	Person* p=nullptr;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->name == name && list[i]->getType() == type) {
			
			p = list[i];
			break;//提高效率
		}
	}
	return p;
}
vector<Person*>AddressBook::getByType(string type)const {
	vector<Person*>res;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getType() == type) { res.push_back(list[i]); }
	}
	return res;
}
void AddressBook::sortByName() {
	sort(list.begin(), list.end(), [](Person* a, Person* b) {
		return a->name < b->name;
		}
	);
}
void AddressBook::sortByBirthday(){
	sort(list.begin(), list.end(), [](Person* a, Person* b) {
		if (a->birth.y != b->birth.y) { return a->birth.y < b->birth.y; }
		else if (a->birth.m != b->birth.m) { return a->birth.m < b->birth.m; }
		else return a->birth.d < b->birth.d;
		});
}
int AddressBook::countByMonth(int month)const {
	int num = 0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->birth.m == month) {
			num++;
		}
	}
	return num;
}
void AddressBook::getToday(int &outYear,int&outMonth, int&outDay)const {
	time_t now = time(nullptr);//获取当前系统的时间戳
	tm ltm;  
	localtime_s(&ltm, &now);  
	//转化成本地时间
	outYear = ltm.tm_year + 1900;
	outMonth = ltm.tm_mon + 1;
	outDay = ltm.tm_mday;
}
//工具函数，判断是否是闰年
static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100!=0) || (year % 400 == 0);
}
//工具函数，仅再这个文件内调用,算现在是年中第几天
static int getDayOfYear(int year,int mon, int day) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year)) { days[2] = 29; };
	int sum = 0;
	for (int i = 1; i < mon; i++) {
		sum += days[i];
	}
	return sum + day;
}
//返回生日是星期几
 string AddressBook::getWeekDay(int year, int month, int day)const {
	tm t = { 0 };//定义自带tm结构体，初始化为0
	//把生日输入
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	mktime(&t);//系统自动算星期几
	const char* weeks[] = { "周日","周一","周二","周三","周四","周五","周六" };
	return weeks[t.tm_wday];
}
vector<Person*>AddressBook::findBirthIn5DaysAuto()const {
	vector<Person*>res;
	int todayYear,todayMon, todayDay;
	getToday(todayYear,todayMon, todayDay);
	int today = getDayOfYear(todayYear,todayMon, todayDay);
	int totalday = isLeapYear(todayYear) ? 366: 365;
	for (int i = 0; i < list.size(); i++) {
		int bMon = list[i]->birth.m;
		int bDay = list[i]->birth.d;
		int birthday = getDayOfYear(todayYear, bMon, bDay);
		int diff = birthday - today;
		if (diff > 0 && diff <= 5) { res.push_back(list[i]); }
		else if (diff < 0) {
			int totaldiff = totalday - today + birthday;
			if (totaldiff <= 5) { res.push_back(list[i]); }
		}
	}
	return res;
}
void AddressBook::generateBirthdayMsg(Person* p)const {
	if (!p) { return; }//防止空指针
	string filename = "祝" + p->name + "生日快乐.txt";
	ofstream f(filename);
	f << p->name << "：" << endl;
	f << "       祝生日快乐，" <<p->birthdaymsg()<< endl;
	f << "                                     王烁涵" << endl;
	f.close();
}
void AddressBook::generateAllBirthdayMsgs() const{
	vector<Person*>all = findBirthIn5DaysAuto();
	for (int i = 0; i < all.size(); i++) {
		generateBirthdayMsg(all[i]);
	}
}
AddressBook::~AddressBook() {
	for (int i = 0; i < list.size(); i++) {
		delete list[i];
	}
	list.clear();
}