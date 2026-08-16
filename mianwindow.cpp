


#pragma once
#include"mainwindow.h"
#include"addressbook.h"
#include"ui_mainwindow.h"
#include<ShowAllDialog.h>
#include"AddDialog.h"
#include"QMessageBox"
#include"DelDialog.h"
#include"FindResultDialog.h"
#include"SearchByMonth.h"
#include"ModifyDialog.h"
#include"FindBIrthdayIn5DaysDialog.h"
addressbookClass::addressbookClass(QWidget* parent)
    : QMainWindow(parent)
{
    m_book.loadFromFile();//打开时自动提取文件里的联系人
    ui.setupUi(this);
}

addressbookClass::~addressbookClass()
{
    m_book.saveToFile();
}

// 显示所有联系人按钮
void addressbookClass::on_btn_showAll_clicked()
{
    auto list = m_book.getAllPerson();
    if (list.empty()) {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("暂无联系人"));
        return;
    }
    QMessageBox  askDialog(this);
    askDialog.setWindowTitle(QString::fromLocal8Bit("选择排序方式"));
    askDialog.setText(QString::fromLocal8Bit("请选择您的排序方式："));
    askDialog.setIcon(QMessageBox::Question);
    //加入中文按钮，设置ActionRole说明按钮属于自定义属性
    QPushButton* btnName = askDialog.addButton(QString::fromLocal8Bit("按姓名排序"),QMessageBox::ActionRole);
    QPushButton* btnBirth = askDialog.addButton(QString::fromLocal8Bit("按生日排序"), QMessageBox::ActionRole);
    QPushButton* btnCancel = askDialog.addButton(QString::fromLocal8Bit("取消"), QMessageBox::ActionRole);
    askDialog.exec();
    if (askDialog.clickedButton() == btnName) {
        m_book.sortByName();
    }
    else  if (askDialog.clickedButton() == btnBirth) {
        m_book.sortByBirthday();
    }
    else  if (askDialog.clickedButton() == btnCancel||askDialog.clickedButton() == nullptr) {
       
        return;
    }
    auto sortedList = m_book.getAllPerson();
    ShowAllDialog d(sortedList, this);
    d.exec();
}
void addressbookClass::on_btn_add_clicked()
{
    AddDialog d(this);//作为主窗口的子窗口
    if (d.exec() == QDialog::Accepted) {
        Person* p = d.getNewPerson();

        if (p != nullptr) {
            m_book.addPerson(p);
            m_book.saveToFile();
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("已添加成功并保存！"));
        }
    }
}
void addressbookClass::on_btn_del_clicked() {
    DelDialog d(this);
    if (d.exec() == QDialog::Accepted) {
        string delname = d.getname();
        string delrel = d.getrel();
        string englishType = "";
        if (delrel == "同学") englishType = "Student";
        else if (delrel == "同事") englishType = "Colleague";
        else if (delrel == "朋友") englishType = "Friend";
        else if (delrel == "亲戚") englishType = "Relative";
        bool find = m_book.deletePerson(delname, englishType);
        if (find) {
            m_book.saveToFile();
            QMessageBox::information(this, QString::fromLocal8Bit("提示 "), QString::fromLocal8Bit("已删除成功并保存！"));
        }

        else {
            QMessageBox::warning(this, QString::fromLocal8Bit("提示 "), QString::fromLocal8Bit("查无此人！"));
        }
    }
}
void addressbookClass::on_btn_find_clicked() {
    FindResultDialog d(m_book, this);
    d.exec();
}
void addressbookClass::on_btn_count_clicked() {
    SearchByMonth d(m_book, this);
    d.exec();
}
void addressbookClass::on_btn_modify_clicked() {
    ModifyDialog d(m_book, this);
    if (d.exec() == QDialog::Accepted) {
        QMessageBox::information(this, QString::fromLocal8Bit("提示 "), QString::fromLocal8Bit("该联系人信息已成功原地改写并同步写入文件！ "));
    }
}
void addressbookClass::on_btn_birth_clicked() {
    FindBIrthdayIn5DaysDialog d(m_book, this);
    d.exec();
}