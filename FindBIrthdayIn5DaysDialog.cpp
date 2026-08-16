#include "FindBIrthdayIn5DaysDialog.h"
#include<QMessageBox>
FindBIrthdayIn5DaysDialog::FindBIrthdayIn5DaysDialog(AddressBook& book,QWidget *parent)
	:mbook(book), QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("五天内生日名单"));
	vector<Person*>upcoming = mbook.findBirthIn5DaysAuto();
	if (!upcoming.empty()) { mbook.generateAllBirthdayMsgs(); };
	if (upcoming.empty()) {
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("五天内无人生日！ "));
		return;
	}
	ui.tableWidget->setRowCount(upcoming.size());//设置表格行数
	int curYear, curMon, curDay;
	mbook.getToday(curYear, curMon, curDay);
	for (int i = 0; i < upcoming.size(); i++) {
		Person* p = upcoming[i];
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromLocal8Bit(p->name.c_str())));

		// 第 2 列：关系（类别）
		QString typeStr;
		if (p->getType() == "Student") typeStr = QString::fromLocal8Bit("同学");
		else if (p->getType() == "Colleague") typeStr = QString::fromLocal8Bit("同事");
		else if (p->getType() == "Relative") typeStr = QString::fromLocal8Bit("亲戚"); 
		else if (p->getType() == "Friend") typeStr = QString::fromLocal8Bit("朋友");
			ui.tableWidget->setItem(i, 1, new QTableWidgetItem(typeStr));

		// 第 3 列：生日 ? 成员函数算出的星期几
		string weekStdStr = mbook.getWeekDay(curYear, p->birth.m, p->birth.d);
		QString weekStr = QString::fromLocal8Bit(weekStdStr.c_str());
		QString birthAndWeek = QString::number(p->birth.m) + "-" + QString::number(p->birth.d) +"("+ weekStr+")";
			ui.tableWidget->setItem(i, 2, new QTableWidgetItem(birthAndWeek));

		// 第 4 列：电话
		ui.tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit(p->tel.c_str())));

		// 第 5 列：邮箱
		ui.tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromLocal8Bit(p->email.c_str())));
	}
	if (!upcoming.empty()) {
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("已显示成功并生成生日祝福！ "));
	}
	}



FindBIrthdayIn5DaysDialog::~FindBIrthdayIn5DaysDialog()
{}

