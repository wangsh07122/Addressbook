#pragma once

#include <QDialog>
#include "ui_ShowAllDialog.h"
#include<vector>
#include<Person.h>
using namespace std;
namespace Ui {
	class ShowAllDialog;
}//提前声明这个弹窗类
class ShowAllDialog : public QDialog
{
	Q_OBJECT

public:
	ShowAllDialog(vector<Person*>list,QWidget *parent = nullptr);
	~ShowAllDialog();

private:
	Ui::ShowAllDialogClass ui;
	vector<Person*>m_list;//用于保存联系人
};

