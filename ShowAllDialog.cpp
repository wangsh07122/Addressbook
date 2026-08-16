#include "ShowAllDialog.h"
#include"ui_ShowAllDialog.h"//qt自动生成的UI界面头文件
#include"Person.h"
#include"vector"
#include"relative.h"
#include"student.h"
#include"colleague.h"
#include"friend.h"
#include"QHeaderView"
#include"QMessageBox"
using namespace std;

ShowAllDialog::ShowAllDialog(vector<Person*>list,QWidget *parent)
	: QDialog(parent),m_list(list)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("显示所有联系人"));//设置窗口标题,用QString::fromLocal8Bit防止乱码
	//清空表格原有内容
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);
	
	
    int row = 0;
    for (int i = 0; i < m_list.size();i++) {
        ui.tableWidget->insertRow(row);
        ui.tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromLocal8Bit(m_list[i]->name)));
        ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromLocal8Bit(m_list[i]->tel)));

        QString birth = QString::number(m_list[i]->birth.y) + "-" +
            QString::number(m_list[i]->birth.m) + "-" +
            QString::number(m_list[i]->birth.d);
        ui.tableWidget->setItem(row, 2, new QTableWidgetItem(birth));

        ui.tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromLocal8Bit(m_list[i]->email)));
       
        string engType = m_list[i]->getType();
        QString chineseType = "";
        if (engType == "Student") chineseType = QString::fromLocal8Bit("同学");
        else if (engType == "Colleague") chineseType = QString::fromLocal8Bit("同事");
        else if (engType == "Friend") chineseType = QString::fromLocal8Bit("朋友");
        else if (engType == "Relative") chineseType = QString::fromLocal8Bit("亲戚");

        ui.tableWidget->setItem(row, 4, new QTableWidgetItem(chineseType));
        ui.tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromLocal8Bit(m_list[i]->getExtra().c_str())));
        
        row++;
    }

}

ShowAllDialog::~ShowAllDialog()
{}

