#ifndef SIMULATION_H
#define SIMULATION_H
#include <QObject>
#include <QColor>
#include <QPushButton>

#include "netboy.h"
#include "Canvas.hpp"
#include "Group.hpp"
#include <QTimer>

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = nullptr,
                        Canvas *canvas = nullptr,
                        QPushButton *button=nullptr,
                        NetBoy *netboy=nullptr);
    void setBackgroundColor(QColor val);
    void ctlLight();

signals:

public slots:
    void startSimulateMode();
private:
    //bool isSimulate;
    Canvas *gbCanvas;
    QPushButton *gbButton;
    NetBoy *gbNetBoy;
    QTimer *timer;
};

#endif // SIMULATION_H
