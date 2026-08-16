#pragma once

#include <QDialog>
#include "ui_FindResultDialog.h"
#include"addressbook.h"
class FindResultDialog : public QDialog
{
	Q_OBJECT

public:
	FindResultDialog(AddressBook& book,QWidget *parent = nullptr);
	~FindResultDialog();
private slots:
	void on_btn_ok_clicked();
private:
	Ui::FindResultDialogClass ui;
	AddressBook& m_book;//使用引用防止浅拷贝，到时候析构的时候影响主名单
};

