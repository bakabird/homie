#include "MainWindow.hpp"
#include "nodeservermanager.h"
#include <QApplication>
#include <exception>
#include <QDebug>

int main(int argc, char *argv[])
{
    int status = 255;

    try {
        QApplication a(argc, argv);
        MainWindow w;

        NodeServerManager node(&w);

        // 前去敲node服务器门(开发过程中请注释掉，自行启动服务器，只在发布时开启) author: rdd
        if(node.checkServer()){
            // 创建并显示窗口
            // 在 MainWindow 类的构造函数中已经往窗口中添加了许多UI类，并编写了相应的事件
            w.connect(&w,&MainWindow::willClose,&node,&NodeServerManager::kiilNode);
            w.show();
            // 进入事件循环
            status = a.exec();
        }
    } catch (std::exception &e) {
        qDebug() << e.what();
    }

    return status;
}
