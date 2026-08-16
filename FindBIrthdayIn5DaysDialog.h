#pragma once

#include <QDialog>
#include "ui_FindBIrthdayIn5DaysDialog.h"
#include"addressbook.h"
class FindBIrthdayIn5DaysDialog : public QDialog
{
	Q_OBJECT

public:
	FindBIrthdayIn5DaysDialog(AddressBook& book,QWidget *parent = nullptr);
	~FindBIrthdayIn5DaysDialog();

private:
	Ui::FindBIrthdayIn5DaysDialogClass ui;
	AddressBook& mbook;
};

