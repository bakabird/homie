#include "Simulation.h"

Simulation::Simulation(QObject *parent,
                       Canvas *canvas,
                       QPushButton *button,
                       NetBoy *netboy) : QObject(parent)
{
    //isSimulate = false;
    gbCanvas = canvas;
    gbButton = button;
    gbNetBoy = netboy;

    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(ctlLight()));
}

void Simulation::setBackgroundColor(QColor val){
    gbCanvas->setBackgroundColor(val);
}

void Simulation::startSimulateMode(){
    if(gbButton->text()=="开始模拟"){
 //       isSimulate = true;
        QColor val(23,24,26);
        setBackgroundColor(val);
        gbButton->setText("结束模拟");
        gbNetBoy->switchMode(1);// send a simulation signal to server.

       // timer->start(1000);
    }
    else if(gbButton->text()=="结束模拟"){
 //       isSimulate =false;
        QColor val(255,255,255);
        setBackgroundColor(val);
        gbButton->setText("开始模拟");
    }
}

/*
void Simulation::ctlLight(){
    for(){  }
    int sts = query();
    if(query()== ){

    }
          timer->start(1000);

}
*/
