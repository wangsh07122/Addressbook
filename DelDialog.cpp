#include "DelDialog.h"
#include<QMessageBox>
DelDialog::DelDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("删除联系人"));
}
void DelDialog::on_btn_ok_clicked() {
	name = ui.edit_name->text().toLocal8Bit().constData();
	relation = ui.comboBox->currentText().toLocal8Bit().constData();//将这个强行改成GBK编码
	if (name.empty()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("姓名不能为空！"));
		return;
	}
	else { accept(); }
}
std::string DelDialog::getname() {
	return name;
}
std::string DelDialog::getrel() {
	return relation;
}
DelDialog::~DelDialog()
{}


