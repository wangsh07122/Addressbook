#pragma once

#include <QDialog>
#include "ui_DelDialog.h"
#include<string>
namespace Ui {
	class DelDialogClass;
}
class DelDialog : public QDialog
{
	Q_OBJECT

public:
	DelDialog(QWidget *parent = nullptr);
	~DelDialog();
	std::string getname();
	std::string getrel();
private slots:
	void on_btn_ok_clicked();
private:
	Ui::DelDialogClass ui;
    std::string name;
	std::string relation;
};

