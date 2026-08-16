#include "FindResultDialog.h"
#include<QMessageBox>
#include<vector>
#include"person.h"
#include<string>
FindResultDialog::FindResultDialog(AddressBook& book,QWidget *parent)
	: m_book(book),QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("按姓名查找联系人"));
	//初始化表格
	ui.tableWidget->setColumnCount(6);
	QStringList headers;
	headers << QString::fromLocal8Bit("姓名")
		<< QString::fromLocal8Bit("电话")
		<< QString::fromLocal8Bit("生日")
		<< QString::fromLocal8Bit("邮箱")
		<< QString::fromLocal8Bit("关系")
		<< QString::fromLocal8Bit("额外信息");
	ui.tableWidget->setHorizontalHeaderLabels(headers);
}
void FindResultDialog::on_btn_ok_clicked() {
	std::string searchname = ui.name->text().toLocal8Bit().constData();
	if (searchname.empty()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("姓名不能为空！"));
		return;
	}
	std::vector<Person*>result = m_book.searchByName(searchname);
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);
	if (result.empty()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("查无此人！"));
		return;
	}
	int row = 0;
	for (size_t i = 0; i < result.size(); i++) {
		ui.tableWidget->insertRow(row);

		
		ui.tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromLocal8Bit(result[i]->name.c_str())));
		ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromLocal8Bit(result[i]->tel.c_str())));

		
		QString birth = QString::number(result[i]->birth.y) + "-" +
			QString::number(result[i]->birth.m) + "-" +
			QString::number(result[i]->birth.d);
		ui.tableWidget->setItem(row, 2, new QTableWidgetItem(birth));

		ui.tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromLocal8Bit(result[i]->email.c_str())));

		
		std::string engType = result[i]->getType();
		QString chineseType = "";
		if (engType == "Student") chineseType = QString::fromLocal8Bit("同学");
		else if (engType == "Colleague") chineseType = QString::fromLocal8Bit("同事");
		else if (engType == "Friend") chineseType = QString::fromLocal8Bit("朋友");
		else if (engType == "Relative") chineseType = QString::fromLocal8Bit("亲戚");
		ui.tableWidget->setItem(row, 4, new QTableWidgetItem(chineseType));

		// 额外信息
		ui.tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromLocal8Bit(result[i]->getExtra().c_str())));

		row++;
	}
}

FindResultDialog::~FindResultDialog()
{}

