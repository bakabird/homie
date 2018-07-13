#include "Simulation.h"
#include <vector>
#include "IFillable.hpp"
Simulation::Simulation(QObject *parent,
                       Canvas *canvas,
                       QPushButton *button,
                       NetBoy *netboy,
                       QToolBar *qtb) : QObject(parent)
{
    isSimulate = false;
    gbCanvas = canvas;
    gbButton = button;
    gbNetBoy = netboy;
    tb = qtb;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ctlLight()));
}

void Simulation::setBackgroundColor(QColor val){
    gbCanvas->setBackgroundColor(val);
}

void Simulation::startSimulateMode(){
    if(gbButton->text()=="开始模拟"){
        isSimulate = true;
        tb->hide();
        QColor val(35,37,39);
        setBackgroundColor(val);
        gbButton->setText("结束模拟");
        gbNetBoy->switchMode(1);// send a simulation signal to server.

        timer->start(500);
    }
    else if(gbButton->text()=="结束模拟"){
        isSimulate =false;
        tb->show();
        QColor val(255,255,255);
        setBackgroundColor(val);
        gbButton->setText("开始模拟");
        gbNetBoy->switchMode(0);// send a simulation signal to server.
    }
}


void Simulation::ctlLight(){
    if(isSimulate){
        QJsonArray JArr = gbNetBoy->allLightsSta();
        int size = JArr.size();
        std::vector<VisualEntity*> child=gbCanvas->m_mainGroup->m_children;
        int num=child.size();
        for(int j=0;j<num;j++){
            for(int i = 0;i < JArr.size();i++){
                QJsonObject JItm = JArr.at(i).toObject();
                int eid = JItm.value("eid").toInt();
                int lightUp = JItm.value("lightUp").toInt();

                if((child[j]->getCompoentType()== 1)&& (child[j]->getCompoentId() == eid)){

                    IFillable *a = dynamic_cast<IFillable *>(child[j]);
                    if(lightUp == 1)
                        a->setFillColor(QColor(240, 124, 59));
                    else
                        a->setFillColor(QColor(85, 255, 127));
                    gbCanvas->repaint();
                }
            }
        }

    }

    timer->start(500);

}

