
#include "AddDialog.h"
#include"student.h"
#include"colleague.h"
#include"friend.h"
#include"relative.h"
#include<QMessageBox>
AddDialog::AddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);//执行界面初始化，加载编辑好的ui
	this->setWindowTitle(QString::fromLocal8Bit("添加联系人"));//设置界面标题
	ui.dateEdit->setCalendarPopup(true);//设置一个日历供挑选日期，使更美观
}

AddDialog::~AddDialog()
{
}
Person* AddDialog::getNewPerson()const {
	return m_newPerson;
}
void AddDialog::on_btn_ok_clicked() {
	string name = ui.edit_name->text().toLocal8Bit().constData();//确保输入中文不乱码
	string tel = ui.edit_tel->text().toLocal8Bit().constData();
	string email = ui.edit_email->text().toLocal8Bit().constData();
	string extra = ui.edit_extra->text().toLocal8Bit().constData();
	int y = ui.dateEdit->date().year();
	int m = ui.dateEdit->date().month();
	int d = ui.dateEdit->date().day();
	Person::MyDate birth(y, m, d);
	if (name.empty() || tel.empty() || email.empty()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("三项不能为空！"));
		return;
	}
	QString currentType = ui.comboBox->currentText();
	if (currentType == QString::fromLocal8Bit("同学")) {
		m_newPerson = new Student(name, birth, tel, email, extra);
	}
	else if (currentType == QString::fromLocal8Bit("同事")) {
		m_newPerson = new Colleague(name, birth, tel, email, extra);
	}
	else if (currentType == QString::fromLocal8Bit("朋友")) {
		m_newPerson = new Friend(name, birth, tel, email, extra);
	}
	else if (currentType == QString::fromLocal8Bit("亲戚")) {
		m_newPerson = new Relative(name, birth, tel, email, extra);
	}
	accept();//关闭对话框，并将exec的返回值设为accept，使数据可以被保存
}
void AddDialog::on_btn_cancel_clicked() {
	reject();//exec返回值设为reject，不保存数据
}
