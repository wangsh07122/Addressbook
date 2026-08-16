#include "addressbook.h"
#include <QApplication>
#include<mainwindow.h>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    
    addressbookClass w;
    w.show();

    return a.exec();//exec使窗口直到被关闭或完成功能才会消失；
}