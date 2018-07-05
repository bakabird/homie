#include "helloqt.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloQt w;
    w.show();



    return a.exec();
}
