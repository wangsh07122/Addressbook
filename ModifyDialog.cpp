#include "ModifyDialog.h"
#include<string>
#include<QMessageBox>
#include<QInputDialog>
#include <QCalendarWidget> //引入日历小部件
#include <QVBoxLayout>//垂直布局
ModifyDialog::ModifyDialog(AddressBook& book, QWidget* parent)
	:m_book(book), QDialog(parent)
{
	ui.setupUi(this);
}
void ModifyDialog::on_btn_ok_clicked() {

	QString txtSelectTitle = "Select Item";
	QString txtSelectText = "Please select the information to modify:";
	QString txtTelTitle = "Modify Phone";
	QString txtEmailTitle = "Modify Email";
	QString txtBirthTitle = "Modify Birthday";
	QString txtExtraTitle = "Modify Extra Info";
	QString txtCancel = "Cancel";

	std::string tomodifyname = ui.edit_name->text().toLocal8Bit().constData();
	QString type = ui.comboBox->currentText();
	std::string entype;

	if (type == QString::fromLocal8Bit("同学")) {
		entype = "Student";
	}
	else if (type == QString::fromLocal8Bit("同事")) {
		entype = "Colleague";
	}
	else if (type == QString::fromLocal8Bit("亲戚")) {
		entype = "Relative";
	}
	else if (type == QString::fromLocal8Bit("朋友")) {
		entype = "Friend";
	}
	Person* tomodify = m_book.searchByNameandType(tomodifyname, entype);
	if (tomodify == nullptr) {
		QMessageBox::warning(this, "Warning", "Contact not found!"); return;
	}
	else {
		QMessageBox askDialog(this);
		askDialog.setWindowTitle(txtSelectTitle);
		askDialog.setText(txtSelectText);
		askDialog.setIcon(QMessageBox::Question);
		QPushButton* btnTel = askDialog.addButton(txtTelTitle, QMessageBox::ActionRole);
		QPushButton* btnEmail = askDialog.addButton(txtEmailTitle, QMessageBox::ActionRole);
		QPushButton* btnBirth = askDialog.addButton(txtBirthTitle, QMessageBox::ActionRole);
		QPushButton* btnExtra = askDialog.addButton(txtExtraTitle, QMessageBox::ActionRole);
		QPushButton* btnCancel = askDialog.addButton(txtCancel, QMessageBox::RejectRole);
		askDialog.exec();
		if (askDialog.clickedButton() == btnCancel || askDialog.clickedButton() == nullptr) {
			return;
		}
		if (askDialog.clickedButton() == btnTel) {
			QString newTel = QInputDialog::getText(this, "Modify Phone", "Enter new phone number:");
			if (!newTel.isEmpty()) {
				tomodify->tel = newTel.toLocal8Bit().constData();
			}
			else { QMessageBox::warning(this, "Warning", "Input cannot be empty!"); }
		}
		else if (askDialog.clickedButton() == btnEmail) {
			QString newE = QInputDialog::getText(this, "Modify Email", "Enter new email address:");
			if (!newE.isEmpty()) {
				tomodify->email = newE.toLocal8Bit().constData();
			}
			else { QMessageBox::warning(this, "Warning", "Input cannot be empty!"); }
		}
		else if (askDialog.clickedButton() == btnExtra) {
			QString newEx = QInputDialog::getText(this, "Modify Extra Info", "Enter new extra information:");
			if (!newEx.isEmpty()) {
				tomodify->setExtra(newEx.toLocal8Bit().constData());
			}
			else { QMessageBox::warning(this, "Warning", "Input cannot be empty!"); }
		}
		else if (askDialog.clickedButton() == btnBirth) {
			// 实例化一个临时弹窗和日历组件
			QDialog calendarDialog(this);
			calendarDialog.setWindowTitle("Modify Birthday");

			// 创建日历小部件
			QCalendarWidget* calendar = new QCalendarWidget(&calendarDialog);

			// 创建一个垂直收纳盒，用来把日历和按钮整整齐齐地从上到下排好，防止它们重叠堆在左上角
			QVBoxLayout* layout = new QVBoxLayout(&calendarDialog);
			layout->addWidget(calendar);

			//加一个确定按钮，让用户选好了点它
			QPushButton* btnConfirm = new QPushButton("Confirm", &calendarDialog);
			layout->addWidget(btnConfirm);

			// 点击确定按钮时，关闭弹窗并返回 Accepted 暗号
			connect(btnConfirm, &QPushButton::clicked, &calendarDialog, &QDialog::accept);

			// 阻塞式拉起日历弹窗
			if (calendarDialog.exec() == QDialog::Accepted) {
				// 直接获取用户在日历上用鼠标戳中的那个日期对象
				QDate selectedDate = calendar->selectedDate();


				tomodify->birth.y = selectedDate.year();  // 拿到年份
				tomodify->birth.m = selectedDate.month(); // 拿到月份
				tomodify->birth.d = selectedDate.day();   // 拿到天数
			}
			else {
				return; // 用户如果点了红叉关闭日历，直接安全拦截
			}
		}
	}
	this->accept();
}
ModifyDialog::~ModifyDialog()
{
}