#pragma once



#include <QtWidgets/QMainWindow>// 引入 Qt 标准主窗口基类头文件
#include<addressbook.h>
#include<ui_mainwindow.h>//找到我的ui文件
namespace Ui {
    class addressbookClass;
}

class addressbookClass : public QMainWindow
{
    Q_OBJECT

public:
    addressbookClass(QWidget* parent = nullptr);
    ~addressbookClass();
    string getname();
    string getrel();

private slots:
    void on_btn_showAll_clicked();
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_find_clicked();
    void on_btn_count_clicked();
    void on_btn_modify_clicked();//修改联系人这个功能用中文总是被吞引号，最后决定用英文
    void on_btn_birth_clicked();
private:
    Ui::addressbookClass ui;  //定义一个ui类调用ui
    AddressBook m_book;      
};

