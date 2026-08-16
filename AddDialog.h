#pragma once

#include <QDialog>
#include "ui_AddDialog.h"
#include"Person.h"
namespace Ui{
	class AddDialogClass;
}//将qt自动生成界面放在独立的命名位置
class AddDialog : public QDialog
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = nullptr);
	~AddDialog();
	Person* getNewPerson()const;
private slots:
	void on_btn_ok_clicked();
	void on_btn_cancel_clicked();
private:
	Ui::AddDialogClass ui;//ui类，管理界面的控件
	Person* m_newPerson = nullptr;
};

