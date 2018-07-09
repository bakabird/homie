#include "MainWindow.hpp"
#include <QApplication>
#include <exception>
#include <QDebug>

#include <QProcess>


int main(int argc, char *argv[])
{
    int status;

    try {
        QApplication a(argc, argv);

        // 创建并显示窗口
        // 在 MainWindow 类的构造函数中已经往窗口中添加了许多UI类，并编写了相应的事件
        MainWindow w;
        w.show();

        // 进入事件循环
        status = a.exec();
    } catch (std::exception &e) {
        qDebug() << e.what();
    }

    return status;
}
