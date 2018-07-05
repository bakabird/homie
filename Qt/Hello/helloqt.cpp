#include "helloqt.h"
#include "ui_helloqt.h"

HelloQt::HelloQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloQt)
{
    ui->setupUi(this);
    connect(this->ui->graphicsView,SIGNAL(clicked(bool)),this,SLOT(ChangeLable()));
}


HelloQt::~HelloQt()
{
    delete ui;
}
void HelloQt::ChangeLable(){
    //this->ui->label1->setText("Hello~");
}

