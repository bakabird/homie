#ifndef HELLOQT_H
#define HELLOQT_H

#include <QMainWindow>

namespace Ui {
class HelloQt;
}

class HelloQt : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloQt(QWidget *parent = 0);
    ~HelloQt();

public slots:
    void ChangeLable();
private:
    QString hstr;
    Ui::HelloQt *ui;
};

#endif // HELLOQT_H
