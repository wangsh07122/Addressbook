#pragma once

#include <QDialog>
#include "ui_ModifyDialog.h"
#include"person.h"
#include"addressbook.h"
class ModifyDialog : public QDialog
{
	Q_OBJECT

public:
	ModifyDialog(AddressBook& book,QWidget *parent = nullptr);
	~ModifyDialog();
private slots:
	void on_btn_ok_clicked();
private:
	Ui::ModifyDialogClass ui;
	AddressBook& m_book;
};

