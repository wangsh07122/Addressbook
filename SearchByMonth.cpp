#include "SearchByMonth.h"
#include<QMessageBox>
SearchByMonth::SearchByMonth(AddressBook& book,QWidget *parent)
	:m_book(book), QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("按月统计生日人数"));
}
void SearchByMonth:: on_btn_ok_clicked() {
	int month = ui.comboBox->currentIndex() + 1;
	int num = m_book.countByMonth(month);
	QString result;
	if (num != 0) {
		result = QString::fromLocal8Bit("在%1月出生的共有%2人 ").arg(month).arg(num);
		
	}
	else {
		result = QString::fromLocal8Bit("没有人在%1月出生 ").arg(month);
	}
	QMessageBox::information(this, QString::fromLocal8Bit("统计结果 "), result);
	return;
}
SearchByMonth::~SearchByMonth()
{}

