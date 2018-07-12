#include "Simulation.h"

Simulation::Simulation(QObject *parent, Canvas *canvas) : QObject(parent)
{
    gbCanvas = canvas;
}

void Simulation::setBackgroundColor(QColor val){
    gbCanvas->setBackgroundColor(val);
}

void Simulation::startSimulate(){
    QColor val(10,10,10);
    setBackgroundColor(val);
}
