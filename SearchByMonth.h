#pragma once

#include <QDialog>
#include "ui_SearchByMonth.h"
#include"addressbook.h"
class SearchByMonth : public QDialog
{
	Q_OBJECT

public:
	SearchByMonth(AddressBook& book,QWidget *parent = nullptr);
	~SearchByMonth();
private slots:
	void on_btn_ok_clicked();
private:
	Ui::SearchByMonthClass ui;
	AddressBook& m_book;
};

